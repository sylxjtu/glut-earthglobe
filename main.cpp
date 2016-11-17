#include <GL/glew.h>
#include <GL/glut.h>
#include "TextureImage.h"

double angle = 0;
double speed = 5;
double accelerate = 0;
const double FPS = 60;

TextureImage t;

void display();

void init() {
    t.loadFile("earth.bmp", 1024, 1024);
    t.loadTexture();
    GLfloat light_position[] = {1.0, 0.3, 0.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void idle() {
    speed += accelerate / FPS;
    angle += speed / FPS;
    display();
}

void drawSphere(int radius) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t.textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    GLUquadricObj *sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricTexture(sphere, TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, radius, 1024, 1024);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -10, 0, 0, 0, 0, 0, 0, 1);
    glRotated(angle, 0, 0, 1);
    drawSphere(5);
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GL_RGB | GL_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Title");
    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
}