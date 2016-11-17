//
// Created by sylxjtu on 2016/11/17.
//

#ifndef GLUT_TEXTUREIMAGE_H
#define GLUT_TEXTUREIMAGE_H

#include <GL/glut.h>
#include <cstdio>

struct TextureImage {
    GLuint textureID;
    unsigned char *data;
    int width, height;
    FILE *file;

    void loadFile(const char *filename, int width, int height);

    GLuint loadTexture();
};

#endif //GLUT_TEXTUREIMAGE_H
