//============================================================================
// Name        : cTelas.cpp
// Author      : Francisco Dominguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <GL/glut.h>
using namespace std;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    //glFlush();
    glutSwapBuffers();
}

void managerKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        {
            exit(0);
        }
    }
    (void)(x);
    (void)(y);
}

void managerResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	cout << "!!!Hello World GIT OpenGL!!!" << endl; // prints !!!Hello World!!!
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world :D");
    glutDisplayFunc(displayMe);
    glutKeyboardFunc(managerKeyboard);
    glutReshapeFunc(managerResize);

    glutMainLoop();
    return 0;
}
