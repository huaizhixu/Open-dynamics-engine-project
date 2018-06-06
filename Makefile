all:prog 
prog:prog.cpp objDefine.cpp
	g++ -o prog  -I/home/noel/libraries/ode-0.13/include -I/home/noel/libraries/ode-0.13/include/drawstuff-DdTRIMESH_ENABLED-DdDOUBLE  -L/usr/local/lib -L/home/noel/libraries/ode-0.13/drawstuff/src/.libs    prog.cpp objDefine.cpp -lode -ldrawstuff -lGL -lGLU -lglut -lX11

