#ifdef __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <GLUT/glut.h>
        #include <OpenGL/OpenGL.h>
    #endif
#elif defined _WIN32 || defined _WIN64
    #include <string>
	#include <assert.h>
	#include <cmath>
	#include <iostream>
	#include <vector>
	#include <windows.h>
	#include <GL/gl.h>
	#include <GL/glut.h>
	#include <GL/glu.h>
	using namespace std;
#endif

typedef vector<int> list;
vector<list> ls, cs;
int old_x, old_y, new_x, new_y, cx, cy, cr;
int mouse_type;

/* breseman画线算法 */
void line(int x1, int y1, int x2, int y2) {
glBegin(GL_POINTS);
if (x1==x2 && y1==y2) {
   glVertex2i(x1, y1);
   return;
}
if (x1>x2) {
   swap(x1, x2);
   swap(y1, y2);
}
glVertex2d(x1, y1);
int dy=abs(y2-y1);
int dx=abs(x2-x1);
if (dx>=dy) {
   int incy=(dy!=0?dy/(y2-y1):0);
   int p=2*dy-dx;
   int dy2=2*dy;
   int dd2=2*(dy-dx);
   int x, y=y1;
   for (x=x1+1; x<=x2; ++x) {
    if (p<0) {
     glVertex2i(x, y);
     p+=dy2;
    }else {
     y+=incy;
     glVertex2i(x, y);
     p+=dd2;
    }
   }
}else {
   if (y1>y2) {
    swap(x1, x2);
    swap(y1, y2);
   }
   int incx=(dx!=0?dx/(x2-x1):0);
   int p=2*dx-dy;
   int dx2=2*dx;
   int dd2=2*(dx-dy);
   int x=x1, y;
   for (y=y1+1; y<=y2; ++y) {
    if (p<0) {
     glVertex2i(x, y);
     p+=dx2;
    }else {
     x+=incx;
     glVertex2i(x, y);
     p+=dd2;
    }
   }
}
glEnd();
}


/* 中点圆算法 */
void circle(int cx, int cy, int r) {
int x=0, y=r;
float p=1.25-r;
while (x<=y) {
   glBegin(GL_POINTS);
    glVertex2i(cx+x, cy+y);
    glVertex2i(cx-x, cy+y);
    glVertex2i(cx-x, cy-y);
    glVertex2i(cx+x, cy-y);
    glVertex2i(cx+y, cy+x);
    glVertex2i(cx-y, cy+x);
    glVertex2i(cx-y, cy-x);
    glVertex2i(cx+y, cy-x);
   glEnd();
   if (p<0) {
    ++x;
    p+=2*x+1;
   }else {
    p+=2*x-2*y+5;
    ++x;
    --y;
   }
}
}

void draw(){
int i;
for (i=0; i<ls.size(); ++i)
   line(ls[i][0], ls[i][1], ls[i][2], ls[i][3]);
for (i=0; i<cs.size(); ++i)
   circle(cs[i][0], cs[i][1], cs[i][2]);
if(mouse_type == 1)
   line(old_x, old_y, new_x, new_y);
if(mouse_type == 3)
   circle(cx, cy, cr);
}

void display() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3i(0, 0, 0);
draw();
glutSwapBuffers();
}

void keyboard( unsigned char key, int x, int y) {
switch (key) {
   case 27:
    return;break;
   case 'a':
   case 'A':
    break;
   default:
    if (key<='z' && key>='a' || key<='Z' && key>='A' || key<='9' && key>='0'){
     cout<<char(key);
    }else{
     cout<<"\n字符码为 "<<static_cast<int>(key);
     display();
    }
}
}


void mouseclick( int button, int state, int x, int y ){
cout<<"("<<x<<","<<y<<")";
switch ( button ) {
   case GLUT_LEFT_BUTTON:
    if ( state == GLUT_DOWN ) {
     cout<<"左键被按下";
     old_x = x;
     old_y = 600-y;
     mouse_type = 1;
    }else if ( state == GLUT_UP ) {
     cout<<"左键被松开";
     list l;
     l.push_back(old_x);
     l.push_back(old_y);
     l.push_back(x);
     l.push_back(600-y);
     ls.push_back(l);
     mouse_type = 0;
     glutPostRedisplay();
     for(int i=0; i<ls.size(); ++i)
      cout<<endl<<"line_"<<i<<": "<<ls[i][0]<<","<<ls[i][1]<<"   "<<ls[i][2]<<","<<ls[i][3];
    }
    break;
   case GLUT_MIDDLE_BUTTON:
    break;
   case GLUT_RIGHT_BUTTON:
    if ( state == GLUT_DOWN ) {
     cout<<"右键被按下";
     cx = x;
     cy = 600-y;
     mouse_type = 3;
    }else if ( state == GLUT_UP ) {
     cout<<"右键被松开";
     list l;
     l.push_back(cx);
     l.push_back(cy);
     cr=int(sqrt(double(x-cx)*(x-cx)+(600-y-cy)*(600-y-cy))+0.5);
     l.push_back(cr);
     cs.push_back(l);
     mouse_type = 2;
     glutPostRedisplay();
     for(int i=0; i<cs.size(); ++i)
      cout<<endl<<"circle_"<<i<<": "<<cs[i][0]<<","<<cs[i][1]<<"   "<<cs[i][2];
    }
    break;
}
}

void screenmotion(int x, int y){
if(mouse_type == 1){
   new_x = x;
   new_y = 600-y;
   cout<<endl<<"new-line:"<<old_x<<","<<old_y<<"   "<<new_x<<","<<new_y<<endl;
}else if(mouse_type == 3){
   cr=int(sqrt(double(x-cx)*(x-cx)+(600-y-cy)*(600-y-cy))+0.5);
   cout<<endl<<"new-circle: "<<cx<<","<<cy<<"   "<<cr<<endl;
}

glutPostRedisplay();
}

void init() {
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-1.0, 600, 0.0, 601);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(100, 50);
glutInitWindowSize(600, 600);
glutCreateWindow("图元算法");
init();
glutDisplayFunc(display);
glutMotionFunc(screenmotion);
glutKeyboardFunc( keyboard );
glutMouseFunc( mouseclick );
glutMainLoop();
return 0;
}

