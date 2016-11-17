//
// Created by sylxjtu on 2016/11/17.
//

#include "TextureImage.h"

void TextureImage::loadFile(const char *filename, int width, int height) {
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Open texture file");
        throw "FileNotFound";
    }
    this->width = width;
    this->height = height;
    data = new unsigned char[width * height * 3];
    fseek(file, 54, SEEK_SET);
    fread(data, width * height * 3, 1, file);
    fclose(file);
}

GLuint TextureImage::loadTexture() {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
    delete[] data;
    return textureID;
}