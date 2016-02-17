#include "Vertex_Array.hpp"

using namespace JMT;

Vertex_Array::Vertex_Array()
{
    glGenVertexArrays(1,&id);
}

void Vertex_Array::bind()
{
    glBindVertexArray(id);
}

void Vertex_Array::unbind()
{
    glBindVertexArray(0);
}

Vertex_Array::~Vertex_Array()
{
    glDeleteVertexArrays(1,&id);
}
