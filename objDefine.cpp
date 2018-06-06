#include "define.h"

MyObject obj[NUMOBJ];
MyJoint joint[NUMJOINT];
dWorldID world;
dBodyID robotBodyID;
int NUMOBJactual,NUMJOINTactual,MAXNUM_bodyGroup;

void objDef()
{
   MAXNUM_bodyGroup=0;
   int n,njoint;
   dMass m;
   dMassSetZero(&m);
   njoint=-1;n=-1;
   
   for(int f=0;f<NUMOBJ;f++)//for initialization
      obj[f].objSemantic=0;
   
   //Walls
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=2;obj[n].side[2]=1;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,1,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=2;obj[n].side[2]=1;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,4,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=2;obj[n].side[2]=1;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,7,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=1;obj[n].side[2]=1;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,9.5,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=10;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,5,0.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=10;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0,5,2.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=13.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,7,0,0.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=1.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1,0,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=3;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.5,0,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=2;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,8,0,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=2;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,11,0,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,13.5,0,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=13.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,7,10,0.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=1.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1,10,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=3;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.5,10,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=2;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,8,10,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=2;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,11,10,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,13.5,10,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=13.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,7,10,2.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=13.94;obj[n].side[1]=0.04;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,7,0,2.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=0.94;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,0.5,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=2;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,3,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=2;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,6,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=0.94;obj[n].side[2]=3;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,9.5,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=6.94;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,3.5,0.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=6.94;obj[n].side[2]=0.99;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14,3.5,2.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=3.94;obj[n].side[2]=3;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,5,2,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=2.94;obj[n].side[1]=0.04;obj[n].side[2]=3;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,3.5,4,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.94;obj[n].side[1]=0.04;obj[n].side[2]=3;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.5,4,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=1;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=4.44;obj[n].side[2]=3;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.3;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,5,7.75,1.5001);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   //ignore contact issue from here
   //Doors and Windows
   n++;
   obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)//store room door
   obj[n].side[0]=0.93;obj[n].side[1]=0.02;obj[n].side[2]=2.2;
   obj[n].body=dBodyCreate(world);
   dMassSetBox(&m,0.7,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dBodySetMass(obj[n].body,&m);
   dBodySetPosition(obj[n].body,1.5,3.95,1.101);//position
   obj[n].color[0]=1;obj[n].color[1]=0.15;obj[n].color[2]=0;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetBody(obj[n].geom,obj[n].body);
   njoint++;
   joint[njoint].joint = dJointCreateHinge(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,0); 
   dJointSetHingeAnchor(joint[njoint].joint,1,3.95,1.101);dJointSetHingeAxis(joint[njoint].joint,0,0,1);
   dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;
   obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)//kitchen-dining hall door
   obj[n].side[0]=0.02;obj[n].side[1]=1.5;obj[n].side[2]=2.2;
   obj[n].body=dBodyCreate(world);
   dMassSetBox(&m,0.7,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dBodySetMass(obj[n].body,&m);
   dBodySetPosition(obj[n].body,5.03,4.75,1.101);//position
   obj[n].color[0]=1;obj[n].color[1]=0.15;obj[n].color[2]=0;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetBody(obj[n].geom,obj[n].body);
   njoint++;
   joint[njoint].joint = dJointCreateSlider(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,0); 
   dJointSetSliderAxis(joint[njoint].joint,0,1,0);//dJointAddSliderForce(joint[njoint].joint,1);
   dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   
   n++;//kitchen north table/cabinet t1
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=3;obj[n].side[1]=0.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.95;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1.5,9.75,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet t2
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.95;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.4,8.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet-top shelf
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,9.5,1.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet-mid shelf
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,9.5,1.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=0.04;obj[n].side[2]=1;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,9,1.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet south-mid shelf
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,7.5,1.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet south-top shelf
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,7.5,1.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=0.04;obj[n].side[2]=1;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,7,1.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=0.04;obj[n].side[2]=1;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,8,1.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen north table/overhead shelf
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.2,8.5,2.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen fridge-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.7;obj[n].side[1]=0.04;obj[n].side[2]=2;
   obj[n].color[0]=0.20;obj[n].color[1]=0.22;obj[n].color[2]=0.9;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.35,7,1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen fridge-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.7;obj[n].side[1]=0.04;obj[n].side[2]=2;
   obj[n].color[0]=0.20;obj[n].color[1]=0.22;obj[n].color[2]=0.9;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.35,6,1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen fridge-top plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.7;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.20;obj[n].color[1]=0.22;obj[n].color[2]=0.9;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.35,6.5,2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen fridge-mid plank(freezer)
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.7;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.20;obj[n].color[1]=0.22;obj[n].color[2]=0.9;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.35,6.5,1.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen fridge-mid plank(cold area)
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.7;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.20;obj[n].color[1]=0.22;obj[n].color[2]=0.9;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,0.35,6.5,0.5);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen oven-top plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=1;obj[n].side[1]=0.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.95;obj[n].color[1]=0.94;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1.5,9.75,0.6);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen oven-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=0.5;obj[n].side[2]=0.6;
   obj[n].color[0]=0.95;obj[n].color[1]=0.94;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1,9.75,0.3);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen oven-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.04;obj[n].side[1]=0.5;obj[n].side[2]=0.6;
   obj[n].color[0]=0.95;obj[n].color[1]=0.94;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,2,9.75,0.3);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen oven-top plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=1;obj[n].side[1]=0.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.95;obj[n].color[1]=0.94;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,1.5,9.75,0.1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-top plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,8.5,2.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=2.2;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7,1.1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=2.2;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,8,1.1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=2.2;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,9,1.1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-bottom long plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,8.5,0.8);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-bottom long plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,8.5,0.5);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-bottom long plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,8.5,0.2);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,9.5,1.3);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,9.5,1.8);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-inner vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=1.4;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.5,1.5);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.5,1);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.5,1.3);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.5,1.6);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-side plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=1;obj[n].side[2]=0.04;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.5,1.9);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-small inner vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=0.2;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.75,0.9);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen large cabinet-small inner vertical plank
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.6;obj[n].side[1]=0.04;obj[n].side[2]=0.2;
   obj[n].color[0]=0.84;obj[n].color[1]=0.22;obj[n].color[2]=0.05;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,4.7,7.25,0.9);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//kitchen middle table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=3;obj[n].side[1]=0.7;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.9;obj[n].color[2]=0.95;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,3.5,6.65,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   //Dining hall
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=1.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,6.5,0.75,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=1.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,9.5,0.75,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=1.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,12.5,0.75,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=1.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,6.5,9.25,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=1.5;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,9.5,9.25,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,14-0.4,4.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall round table
   obj[n].MovableNonMovable=2;obj[n].objType=2;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].radius=0.7;obj[n].length=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetPosition(obj[n].geom,7,6.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall round table
   obj[n].MovableNonMovable=2;obj[n].objType=2;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].radius=0.7;obj[n].length=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetPosition(obj[n].geom,8,3.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall round table
   obj[n].MovableNonMovable=2;obj[n].objType=2;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].radius=0.7;obj[n].length=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetPosition(obj[n].geom,10,6.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall round table
   obj[n].MovableNonMovable=2;obj[n].objType=2;//crucial (nonmovable,box)
   obj[n].side[0]=0.8;obj[n].side[1]=3;obj[n].side[2]=0.04;
   obj[n].radius=0.7;obj[n].length=0.04;
   obj[n].color[0]=0.9;obj[n].color[1]=0.7;obj[n].color[2]=0.1;//color
   obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetPosition(obj[n].geom,11,3.5,0.7);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//dinning hall cashier table
   obj[n].MovableNonMovable=2;obj[n].objType=1;//crucial (nonmovable,box)
   obj[n].side[0]=0.5;obj[n].side[1]=1.5;obj[n].side[2]=0.7;
   obj[n].color[0]=0.8;obj[n].color[1]=0.6;obj[n].color[2]=0.4;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetPosition(obj[n].geom,12,9.25,0.35);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   //movable furnitures and large objects
   //Create the chairs
   for(int f=0;f<10;f++)
   {
      float chairx[10]={5.7,8.5,11.6,5.5,9,13,13.3,3,3,2};
      float chairy[10]={1.0,0.5, 0.8,9.0,9,3.5,  5,1.9,2,2};
      n++;//chair-sitting plank
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.5;obj[n].side[2]=0.5;
      obj[n].body=dBodyCreate(world);
      dMassSetBox(&m,5,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,chairx[f],chairy[f],0.3);//position
      obj[n].color[0]=0.7;obj[n].color[1]=0;obj[n].color[2]=0;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;//chair-back rest
      dReal angle_deg;dMatrix3 R1;angle_deg = -20 * M_PI / 180.0;dRFromAxisAndAngle(R1, 0, 1, 0, angle_deg);//get R
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.02;obj[n].side[1]=0.5;obj[n].side[2]=0.35;
      obj[n].body=dBodyCreate(world);
      dMassSetBox(&m,5,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,chairx[f]-0.3,chairy[f],0.3+0.45);dBodySetRotation(obj[n].body, R1);//position and rotation
      obj[n].color[0]=1;obj[n].color[1]=0;obj[n].color[2]=0;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);dGeomSetRotation(obj[n].geom, R1);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
      dJointSetFixed(joint[njoint].joint);
   }
   for(int f=0;f<5;f++)
   {
      float chairx[5]={7, 10,13.5,7 , 10};
      float chairy[5]={1.2,1,0.6 ,9.0,9 };
      n++;//chair-sitting plank
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.5;obj[n].side[2]=0.5;
      obj[n].body=dBodyCreate(world);
      dMassSetBox(&m,5,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,chairx[f],chairy[f],0.3);//position
      obj[n].color[0]=0.7;obj[n].color[1]=0;obj[n].color[2]=0;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;//chair-back rest
      dReal angle_deg;dMatrix3 R1;angle_deg = 20 * M_PI / 180.0;dRFromAxisAndAngle(R1, 0, 1, 0, angle_deg);//get R
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.02;obj[n].side[1]=0.5;obj[n].side[2]=0.35;
      obj[n].body=dBodyCreate(world);
      dMassSetBox(&m,5,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,chairx[f]+0.3,chairy[f],0.3+0.45);dBodySetRotation(obj[n].body, R1);//position and rotation
      obj[n].color[0]=1;obj[n].color[1]=0;obj[n].color[2]=0;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);dGeomSetRotation(obj[n].geom, R1);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
      dJointSetFixed(joint[njoint].joint);
   }
   
   //Trash bin
      n++;//trash bin base
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.5;obj[n].side[2]=0.01;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,0.5,4.5,0.0);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;//trash bin wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.6;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,0.25,4.5,0.31);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
      dJointSetFixed(joint[njoint].joint);
      n++;//trash bin wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.6;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,0.75,4.5,0.31);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-2].body); 
      dJointSetFixed(joint[njoint].joint);
      n++;//trash bin wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.01;obj[n].side[2]=0.6;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,0.5,4.5+0.26,0.31);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-3].body); 
      dJointSetFixed(joint[njoint].joint);
      n++;//trash bin wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.01;obj[n].side[2]=0.6;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,0.5,4.5-0.26,0.31);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-4].body); 
      dJointSetFixed(joint[njoint].joint);
   
   //movable small objects
      //Tray 1
      n++;//tray base
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.5;obj[n].side[2]=0.01;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.5,6.6,1.81);//position
      obj[n].color[0]=0.55;obj[n].color[1]=0.55;obj[n].color[2]=0.8;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;//tray wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.05;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.25,6.6,1.845);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
      dJointSetFixed(joint[njoint].joint);
      n++;//tray wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.05;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.75,6.6,1.845);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-2].body); 
      dJointSetFixed(joint[njoint].joint);
      dBodySetAngularVel(obj[n-2].body,0,0,10);
      
      //Tray 2
      MAXNUM_bodyGroup++;
      n++;//tray base
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.5;obj[n].side[1]=0.5;obj[n].side[2]=0.01;obj[n]._bodyGroup=MAXNUM_bodyGroup;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.5+6.5,7,1.81);//position
      obj[n].color[0]=0.55;obj[n].color[1]=0.55;obj[n].color[2]=0.8;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;//tray wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.05;obj[n]._bodyGroup=MAXNUM_bodyGroup;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.25+6.5,7,1.82);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
      dJointSetFixed(joint[njoint].joint);
      n++;//tray wall
      obj[n].MovableNonMovable=0;obj[n].objType=1;obj[n].objSemantic=2;//crucial (movable,box)
      obj[n].side[0]=0.01;obj[n].side[1]=0.5;obj[n].side[2]=0.05;obj[n]._bodyGroup=MAXNUM_bodyGroup;
      obj[n].body=dBodyCreate(world);
      dMassSetBoxTotal(&m,0.1,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dBodySetMass(obj[n].body,&m);
      dBodySetPosition(obj[n].body,3.75+6.5,7,1.82);//position
      obj[n].color[0]=0.2;obj[n].color[1]=0.2;obj[n].color[2]=0.2;//color
      obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
      dGeomSetBody(obj[n].geom,obj[n].body);
      dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      njoint++;
      joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-2].body); 
      dJointSetFixed(joint[njoint].joint);
      dBodySetAngularVel(obj[n-2].body,0,0,5);
      
      //Cups
      n++;
      obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=2;//crucial (movable,cylinder)
      obj[n].radius=0.08;obj[n].length=0.1;obj[n].body=dBodyCreate(world);robotBodyID=obj[n].body;
      dMassSetCylinderTotal(&m,0.05,3,obj[n].radius,obj[n].length);
      dBodySetMass(obj[n].body,&m);dBodySetPosition(obj[n].body,0.2,9.5,1.8);
      obj[n].color[0]=0;obj[n].color[1]=1;obj[n].color[2]=0;//color
      obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;
      obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=2;//crucial (movable,cylinder)
      obj[n].radius=0.08;obj[n].length=0.1;obj[n].body=dBodyCreate(world);robotBodyID=obj[n].body;
      dMassSetCylinderTotal(&m,0.05,3,obj[n].radius,obj[n].length);
      dBodySetMass(obj[n].body,&m);dBodySetPosition(obj[n].body,0.3,9.7,1.5);
      obj[n].color[0]=0;obj[n].color[1]=1;obj[n].color[2]=0;//color
      obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      n++;
      obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=2;//crucial (movable,cylinder)
      obj[n].radius=0.08;obj[n].length=0.1;obj[n].body=dBodyCreate(world);robotBodyID=obj[n].body;
      dMassSetCylinderTotal(&m,0.05,3,obj[n].radius,obj[n].length);
      dBodySetMass(obj[n].body,&m);dBodySetPosition(obj[n].body,0.2,8.5,2.8);
      //dBodySetPosition(obj[n].body,0.2,8.5,10.8);
      obj[n].color[0]=0;obj[n].color[1]=1;obj[n].color[2]=0;//color
      obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
      //Plates
      n++;
      obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=2;//crucial (movable,cylinder)
      obj[n].radius=0.1;obj[n].length=0.1;obj[n].body=dBodyCreate(world);robotBodyID=obj[n].body;
      dMassSetCylinderTotal(&m,0.05,3,obj[n].radius,obj[n].length);
      dBodySetMass(obj[n].body,&m);dBodySetPosition(obj[n].body,2.75,6.6,2.8);
      //dBodySetPosition(obj[n].body,4,6.6,5.8);
      obj[n].color[0]=0;obj[n].color[1]=1;obj[n].color[2]=0;//color
      obj[n].geom=dCreateCylinder(space,obj[n].radius,obj[n].length);
      dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   
   
   //Robot and other agents
   n++;//Dummy
   obj[n].MovableNonMovable=0;obj[n].objType=1;//crucial (movable,box)
   obj[n].side[0]=0.4;obj[n].side[1]=0.4;obj[n].side[2]=0.4123;
   obj[n].body=dBodyCreate(world);
   dMassSetBox(&m,5,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dBodySetMass(obj[n].body,&m);
   dBodySetPosition(obj[n].body,2,2,4);//position
   obj[n].color[0]=0;obj[n].color[1]=1;obj[n].color[2]=0;//color
   obj[n].geom=dCreateBox(space,obj[n].side[0],obj[n].side[1],obj[n].side[2]);
   dGeomSetBody(obj[n].geom,obj[n].body);
   dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   
   n++;//The Robot
   MAXNUM_bodyGroup++;
   obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=1;//crucial (movable,cylinder)
   obj[n].radius=0.15;obj[n].length=0.7;obj[n]._bodyGroup=MAXNUM_bodyGroup;
   obj[n].body=dBodyCreate(world);robotBodyID=obj[n].body;
   dMassSetCylinderTotal(&m,10,3,obj[n].radius,obj[n].length);
   dBodySetMass(obj[n].body,&m);
   dReal x=1.6,y=6.5,z=4;//position
   dBodySetPosition(obj[n].body,x,y,z);
   obj[n].color[0]=0.1;obj[n].color[1]=0.6;obj[n].color[2]=0.7;//color
   obj[n].geom=dCreateCCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//Robot upper part
   obj[n].MovableNonMovable=0;obj[n].objType=3;obj[n].objSemantic=1;//crucial (movable,capsule)
   obj[n].radius=0.2;obj[n].length=0.7;obj[n]._bodyGroup=MAXNUM_bodyGroup;
   obj[n].body=dBodyCreate(world);
   dMassSetCapsuleTotal(&m,10,3,obj[n].radius,obj[n].length);
   dBodySetMass(obj[n].body,&m);
   dBodySetPosition(obj[n].body,x,y,z+0.25+0.45+0.001);
   obj[n].color[0]=0.1;obj[n].color[1]=0.6;obj[n].color[2]=0.7;//color
   obj[n].geom=dCreateCapsule(space,obj[n].radius,obj[n].length);
   dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);//###Overlapping geom!
   njoint++;
   joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
   dJointSetFixed(joint[njoint].joint);//robot upper is attached to main
   
   
   n++;//The Agent : ###Note: agent's collision with robot is ignored
   MAXNUM_bodyGroup++;
   obj[n].MovableNonMovable=0;obj[n].objType=2;obj[n].objSemantic=1;//crucial (movable,cylinder)
   obj[n].radius=0.15;obj[n].length=0.7;obj[n]._bodyGroup=MAXNUM_bodyGroup;
   obj[n].body=dBodyCreate(world);
   dMassSetCylinderTotal(&m,10,3,obj[n].radius,obj[n].length);
   dBodySetMass(obj[n].body,&m);
   x=6,y=5,z=4;//position
   dBodySetPosition(obj[n].body,x,y,z);
   obj[n].color[0]=0.97;obj[n].color[1]=0.5;obj[n].color[2]=0.14;//color
   obj[n].geom=dCreateCCylinder(space,obj[n].radius,obj[n].length);
   dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);
   n++;//Robot upper part
   obj[n].MovableNonMovable=0;obj[n].objType=3;obj[n].objSemantic=1;//crucial (movable,capsule)
   obj[n].radius=0.2;obj[n].length=0.7;obj[n]._bodyGroup=MAXNUM_bodyGroup;
   obj[n].body=dBodyCreate(world);
   dMassSetCapsuleTotal(&m,10,3,obj[n].radius,obj[n].length);
   dBodySetMass(obj[n].body,&m);
   dBodySetPosition(obj[n].body,x,y,z+0.25+0.45+0.001);
   obj[n].color[0]=0.97;obj[n].color[1]=0.5;obj[n].color[2]=0.14;//color
   obj[n].geom=dCreateCapsule(space,obj[n].radius,obj[n].length);
   dGeomSetBody(obj[n].geom,obj[n].body);dGeomSetData(obj[n].geom,(MyObject*)&obj[n]);//###Overlapping geom!
   njoint++;
   joint[njoint].joint = dJointCreateFixed(world, 0);dJointAttach(joint[njoint].joint,obj[n].body,obj[n-1].body); 
   dJointSetFixed(joint[njoint].joint);//robot upper is attached to main
   
   
   
   
   NUMOBJactual=n+1;NUMJOINTactual=njoint+1;
   printf("Number of Objects and Joints: %d , %d  \n",NUMOBJactual,NUMJOINTactual);
}
