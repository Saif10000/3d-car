#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>



//------------------------------  reshapeFunction  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------

float translateX=0;
float translateY=0;
void Keyboard(unsigned char key,int x, int y){

        switch(key){

            case 'd' : translateX++;
            break;

            case 'a' : translateX--;
            break;

            case 'w' : translateY++;
            break;

            case 's' : translateY--;
            break;

            case 'f' : glutFullScreen();
            break;

            case 27 : exit(0);
            break;
        }

}


void Front()
{

    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(0.01 ,0.3,0.68);
    glTranslatef(-450,-5,0);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();

    //Front Window
    glColor3ub(138,18,0);
    glPushMatrix();
    glTranslatef(-1.43,0,0);
    glRotatef(-30,0,0,1);
    glScalef(0.01 ,0.3,0.68);
    glutWireCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Back()
{
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(0.01 ,0.3,0.68);
    glTranslatef(450,-5,0);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();

    //Back Window
    glColor3ub(138,18,0);
    glPushMatrix();

    glTranslatef(2.43,0.01,0);
    glRotatef(30,0,0,1);
    glScalef(0.01 ,0.3,0.68);
    glutWireCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Top()
{
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(0.5,0.01,0.68);
    glTranslatef(1,83,0);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Bottom()
{
    //top of car' body
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(1.5,0.01,0.68);
    glTranslatef(0,-65,0);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
    //bottom of car' body
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(1.5,0.01,0.68);
    glTranslatef(0,-237,0);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Left()
{
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(1.5 ,0.3,0.01);
    glTranslatef(0,-5,200);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Right()
{
    glColor3ub(138,18,0);
    glPushMatrix();
    glScalef(1.5 ,0.3,0.01);
    glTranslatef(0,-5,-200);
    glutSolidCube(6);
    glColor3f(0,0,0);
    glutWireCube(6);
    glPopMatrix();
}
void Wheels(int x,int y,int z)
{
    float th;
    glColor3f(1,1,1);
    int j;
    for(j=0;j<30;j++)
    {

        glLineWidth(5.0);
        glBegin(GL_POLYGON );
        for(int i=0;i<360;i++)
        {
            th = i*3.14/180;
            glVertex3f(x+(1*cos(th)),y+(1*sin(th)),z+(0.01*j));
        }
        glEnd();
    }
}


void Car()
{
    Front();
    Back();
    Top();
    Bottom();
    Left();
    Right();
    Wheels(-3.5,-2,2);
    Wheels(3.5,-2,2);
    Wheels(-3.5,-2,-2);
    Wheels(3.5,-2,-2);
}
void Tree(int x2,int y2,int z2)
{
    glPushMatrix();
    glTranslatef(x2,y2,z2);
    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(0, 1, 0);
      glVertex3f( 0, 1, 0);
      glColor3f(0, 1, 0);
      glVertex3f(-1, -1, 1);
      glColor3f(0, 1, 0);
      glVertex3f(1, -1, 1);

      // Back
      glColor3f(0, 1, 0);
      glVertex3f( 0, 1, 0);
      glColor3f(0, 1, 0);
      glVertex3f(-1, -1, -1);
      glColor3f(0, 1, 0);
      glVertex3f(1, -1, -1);

      // Right
      glColor3f(0, 1, 0);
      glVertex3f(0, 1, 0);
      glColor3f(0, 0, 1);
      glVertex3f(1, -1, 1);
      glColor3f(0, 1, 0);
      glVertex3f(1, -1, -1);
      // Left
      glColor3f(0, 1, 0);
      glVertex3f(0, 1, 0);
      glColor3f(0, 0, 1);
      glVertex3f(-1, -1, 1);
      glColor3f(0, 1, 0);
      glVertex3f(-1, -1, -1);

      glPopMatrix();

      glEnd();
}
/*void Sun()
{
    glColor3f(1,1,0);
    glPushMatrix();
    glScalef(-0.7,0,0.68);
    glTranslatef(-30,700,0);
    glutSolidSphere(6,30,30);
    glPopMatrix();
}*/


float theta;
void display (void)
{

    theta = theta+0.1;
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);
    //glRotatef(theta,1,1,0);

    glTranslatef(0+translateX,0+translateY,0);
    glScalef(0.5,0.5,0.5);
    Car();


    glPushMatrix();
    Tree(7,1,5);
    Tree(5,0,4);
    Tree(3,-0.5,3);
    Tree(3,-1.5,2);
    glPopMatrix();

    //Sun();




    glutPostRedisplay();
    glEnd();

    glutSwapBuffers();
}

//--------------------------------  idleFunction  ----------------------------------

void idleFunc (void)
{
    //zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize     (1200, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow       ("20102642");

    glutKeyboardFunc(Keyboard);
    glClearColor (1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);
    glOrtho(-50,50,-50,50,-50,50);


    glClearColor(1,1,1,1);
    texture();


    glutMainLoop();
}
