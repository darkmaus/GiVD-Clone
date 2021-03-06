#include "material.h"

Material::Material() {
    ambient = vec3(0.2,0.2,0.2);
    diffuse = vec3(0.8,0.0,0.0);
    specular = vec3(1.0,1.0,1.0);
    shininess = 20.0;

}


vec3 Material::getSpecular() const
{
    return specular;
}

void Material::setSpecular(const vec3 &value)
{
    specular = value;
}

vec3 Material::getDiffuse() const
{
    return diffuse;
}

void Material::setDiffuse(const vec3 &value)
{
    diffuse = value;
}

vec3 Material::getAmbient() const
{
    return ambient;
}

void Material::setAmbient(const vec3 &value)
{
    ambient = value;
}

void Material::toGPU(QGLShaderProgram *pr) {
    struct {
        GLuint ambient;
        GLuint diffuse;
        GLuint specular;
        GLuint shininess;
    } gl_buffer;

    gl_buffer.ambient = pr->uniformLocation("bufferMat.ambient");
    gl_buffer.diffuse = pr->uniformLocation("bufferMat.diffuse");
    gl_buffer.shininess = pr->uniformLocation("bufferMat.shininess");
    gl_buffer.specular = pr->uniformLocation("bufferMat.specular");

    glUniform3fv(gl_buffer.ambient, 1, ambient);
    glUniform3fv(gl_buffer.diffuse, 1, diffuse);
    glUniform3fv(gl_buffer.specular, 1, specular);
    glUniform1f(gl_buffer.shininess, shininess);
}








