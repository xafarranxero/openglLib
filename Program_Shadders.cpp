#include "Program_Shadders.hpp"
#include "Shadder.hpp"

using namespace JMT;

Program_Shadders::Program_Shadders()
{
    id = glCreateProgram();
}

void Program_Shadders::append(Shadder& referencia)
{
    glAttachShader(id,referencia);
}

void Program_Shadders::link()
{
    glLinkProgram(id);
}

void Program_Shadders::use()
{
    glUseProgram(id);
}

void Program_Shadders::check_shadder_link()
{
    char infolog[513];
    GLint success;

    glGetProgramiv(id, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infolog);
        throw Program_Shadders_Link_Error(std::string("Error to link shadder's program\n") + infolog);
    }
}

Program_Shadders::~Program_Shadders()
{
    glDeleteProgram(id);
}
