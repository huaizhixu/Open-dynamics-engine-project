#include "ode/ode.h"
#include "drawstuff/drawstuff.h"
#ifdef dDOUBLE
#define dsDrawBox dsDrawBoxD
#define dsDrawSphere dsDrawSphereD
#define dsDrawCylinder dsDrawCylinderD
#define dsDrawCapsule dsDrawCapsuleD
#define dsDrawLine dsDrawLineD
#endif 
#define NUMOBJ 1000
#define NUMJOINT 1000

extern dWorldID world;
extern dSpaceID space;
extern dGeomID ground;
extern dJointGroupID contactgroup;
extern int NUMOBJactual,NUMJOINTactual,MAXNUM_bodyGroup; 


typedef struct
{
    dBodyID body;
    dGeomID geom;
    int objType; //1:box 2:cylinder 3:capsule
    int MovableNonMovable;//0 movable, 1 nonmovable_wall 2nonmovable_others
    int objSemantic; //1:robot 2:small_obj
    dReal color[3];
    dReal side[3];
    dReal radius,length;
    int _bodyGroup;
    int test;
} MyObject;

typedef struct
{
   dJointID joint;
} MyJoint;
extern MyObject obj[NUMOBJ];
extern MyJoint joint[NUMJOINT];
extern dBodyID robotBodyID;

void objDef();
