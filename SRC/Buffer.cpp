#include "Buffer.hpp"
#include <iostream>

using namespace std;

using namespace JMT;

Buffer::Buffer()
{
    glCreateBuffers(1,&id);
}

void Buffer::bind(GLenum type)
{
    this->type = type;
    glBindBuffer(type,id);
}

void Buffer::unbind()
{
    glBindBuffer(type,0);
}

void Buffer::bufferData(void* data,size_t size,GLenum type_of_draw)
{
    glBufferData(type,size,data,type_of_draw);
}

void* Buffer::mapBuffer(GLenum access)
{
    return glMapBuffer(id,access);
}

GLboolean Buffer::unmapBuffer()
{
    return glUnmapBuffer(id);
}

Buffer::~Buffer()
{
    glDeleteBuffers(1,&id);
}
