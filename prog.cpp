#include "define.h"

dSpaceID space;
dGeomID ground;
dJointGroupID contactgroup;


static void nearCallback(void *data,dGeomID o1,dGeomID o2)
{
    const int N=10;
    dContact contact[N];  //why so many contact? what is it for? 
    int n=dCollide(o1,o2,N,&contact[0].geom,sizeof(dContact));
    MyObject* obj1=(MyObject*)dGeomGetData(o1);//To get info
    MyObject* obj2=(MyObject*)dGeomGetData(o2);//To get info
    
    
    int isGround=((ground==o1)||(ground==o2));
    int isNonMovable=0,issmallObj=0;
    if(obj1!=NULL && obj2!=NULL)
    {
       //if(obj1->objSemantic==1 && obj2->objSemantic==1)return;
       if(obj1->_bodyGroup!=0 && obj1->_bodyGroup==obj2->_bodyGroup)return;
       //isNonMovable=(obj1->MovableNonMovable==1 || obj1->MovableNonMovable==2)||(obj2->MovableNonMovable==1 || obj2->MovableNonMovable==2);
       issmallObj=(obj1->objSemantic==2)||(obj2->objSemantic==2);
    }
    
    
    if(issmallObj)
    {
        for(int i=0;i<n;i++)
        {
           contact[i].surface.mode=dContactBounce;
           contact[i].surface.mu=dInfinity;
           contact[i].surface.bounce=0.9;
           contact[i].surface.bounce_vel=0.0;
           dJointID c=dJointCreateContact(world,contactgroup,&contact[i]);
           dJointAttach(c,dGeomGetBody(contact[i].geom.g1),dGeomGetBody(contact[i].geom.g2));
        }
    }
    else //if(isGround || isNonMovable)
    {
        for(int i=0;i<n;i++)
        {
           contact[i].surface.mode=dContactBounce;
           contact[i].surface.mu=5;//dInfinity;
           contact[i].surface.bounce=0.9;
           contact[i].surface.bounce_vel=0.0;
           dJointID c=dJointCreateContact(world,contactgroup,&contact[i]);
           dJointAttach(c,dGeomGetBody(contact[i].geom.g1),dGeomGetBody(contact[i].geom.g2));
        }
    }
}


// Simulation loop
static void simLoop (int pause)
{
   
   //For anything related to loop specific actions
      /*static int LoopCount=0;
      LoopCount++;
      if(LoopCount==-1)
      {
      }*/
    
   
   
   dSpaceCollide(space,0,&nearCallback);
   dWorldStep(world,0.001);
   dJointGroupEmpty(contactgroup);
   const dReal *pos,*R;

   for(int f=0;f<NUMOBJactual;f++)
   {
       if(obj[f].MovableNonMovable==0)//Movable with body
       {
          switch (obj[f].objType)
          {
          case 1:
              dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
              pos=dBodyGetPosition(obj[f].body);
              R=dBodyGetRotation(obj[f].body);
              dsDrawBox(pos,R,obj[f].side);
              break;
          case 2:
              dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
   	      pos=dBodyGetPosition(obj[f].body);
              R=dBodyGetRotation(obj[f].body);
   	      dsDrawCylinder(pos,R,obj[f].length,obj[f].radius);
   	      break;
   	  case 3:
   	      dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
   	      pos=dBodyGetPosition(obj[f].body);
              R=dBodyGetRotation(obj[f].body);
   	      dsDrawCapsule(pos,R,obj[f].length,obj[f].radius);
   	      break;
   
          }
       }
       else if(obj[f].MovableNonMovable==1)//nonmovable wall with geom
       {
          switch (obj[f].objType)
          {
          case 1:
              dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
              pos=dGeomGetPosition(obj[f].geom);
              R=dGeomGetRotation(obj[f].geom);
              dReal sides[3];sides[0]=obj[f].side[0]+0.02;sides[1]=obj[f].side[1]+0.02;sides[2]=obj[f].side[2]+0.02;
              dsDrawBox(pos,R,sides);
              break;
          }
       }
       else if(obj[f].MovableNonMovable==2)//nonmovable notwall with geom
       {
          switch (obj[f].objType)
          {
          case 1:
              dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
              pos=dGeomGetPosition(obj[f].geom);
              R=dGeomGetRotation(obj[f].geom);
              dsDrawBox(pos,R,obj[f].side);
              break;
          case 2:
              dsSetColorAlpha(obj[f].color[0],obj[f].color[1],obj[f].color[2],1);
   	      pos=dGeomGetPosition(obj[f].geom);
              R=dGeomGetRotation(obj[f].geom);
   	      dsDrawCylinder(pos,R,obj[f].length,obj[f].radius);
   	      break;
          }
       }
   }
   //Manual draw-for image purpose only
   dReal posm[3],sidesm[3];
   R=dGeomGetRotation(obj[0].geom);//###Just to get 0 angles
     //t1 Sink
     posm[0]=2.5;posm[1]=9.75;posm[2]=0.7;sidesm[0]=0.8;sidesm[1]=0.4;sidesm[2]=0.06;
     dsSetColorAlpha(0.05,0.95,1,1);
     dsDrawBox(posm,R,sidesm);
     //t1 stove
     dsSetColorAlpha(0.25,0.25,0.25,1);
     posm[0]=1.25;posm[1]=9.75;posm[2]=0.7;dsDrawCylinder(posm,R,0.06,0.25);
     dsSetColorAlpha(0.1,0.1,0.1,1);
     posm[0]=1.25;posm[1]=9.75;posm[2]=0.71;dsDrawCylinder(posm,R,0.06,0.15);
     dsSetColorAlpha(0.25,0.25,0.25,1);
     posm[0]=1.75;posm[1]=9.75;posm[2]=0.7;dsDrawCylinder(posm,R,0.06,0.25);
     dsSetColorAlpha(0.1,0.1,0.1,1);
     posm[0]=1.75;posm[1]=9.75;posm[2]=0.71;dsDrawCylinder(posm,R,0.06,0.15);
   
}

// Start function 
void start()
{
  // Set a camera
  static float xyz[3] = {7,-3.0,15.0}; //view position (x,y,z [m])
  static float hpr[3] = {90.0,-70.0,0.0}; //view direction (head, pitch,roll[])
  dsSetViewpoint (xyz,hpr);  //Set a view point
}



// main function
int main (int argc, char **argv)
{ 
  dsFunctions fn; 
  fn.version=DS_VERSION; 
  fn.start=&start; 
  fn.step=&simLoop; 
  fn.command = NULL; 
  fn.stop    = NULL; 
  fn.path_to_textures = "/home/noel/libraries/ode-0.13/drawstuff/textures";

  dInitODE();      
  world = dWorldCreate(); 
  dWorldSetCFM(world,1.0e-9);
  //dWorldSetERP(world,0.8);
  space=dHashSpaceCreate(0);
  contactgroup=dJointGroupCreate(0);
  dWorldSetGravity(world,0,0,-9.8);
  ground=dCreatePlane(space,0,0,1,0);
  MyObject groundMyObject;
  dGeomSetData(ground,(MyObject*)&groundMyObject); 
  objDef();
  
  

  
  
  dsSimulationLoop (argc,argv,800,650,&fn);
  
  dWorldDestroy(world); //Destroy the world 　
  dCloseODE();                 // Close ODE
  return 0;
}
