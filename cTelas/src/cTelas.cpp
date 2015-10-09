//============================================================================
// Name        : cTelas.cpp
// Author      : Francisco Dominguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include <GL/glut.h>
using namespace std;

float newAngle=0;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0f);
    glRotatef(newAngle += 1, 1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    //glFlush();
    glutSwapBuffers();
}
void managerIdle(void)
{
    //usleep(1000);
    glutPostRedisplay();
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
void managerMouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(managerIdle);
        break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
        break;
        default:
        break;
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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world :D GIT!!!");
    glutDisplayFunc(displayMe);
    glutReshapeFunc(managerResize);
    glutMouseFunc(managerMouse);
    glutKeyboardFunc(managerKeyboard);
    glutIdleFunc(managerIdle);

    glutMainLoop();
    return 0;
}
