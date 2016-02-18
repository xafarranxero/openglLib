#include "Shadder.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace JMT;

Shadder::Shadder(GLuint type)
{
    initialize(type);
}

//Shadder::Shadder(GLuint type,const char* shadder)
//{
//    initialize(type);
//    loadFromMemory(shadder);
//}

Shadder::Shadder(GLuint tipo,const char* shadder[],int num)
{
    initialize(type);
    loadFromMemory(shadder,num);
}

void Shadder::initialize(GLuint type)
{
    this->type = type;
    id = glCreateShader(type);
}

Shadder& Shadder::loadFromFile(const char* name)
{
    ifstream fin(name);

    if (!fin.good())
    {
        throw Shadder_File_Not_Founded(string("Error loading shadder's file: \"") + name + "\" doesn't exist");
    }
    else
    {
        std::string code;
        std::string current_line;

        while (fin.good())
        {
            getline(fin,current_line);
            code += current_line + '\n';
        }

        loadFromMemory(code.c_str());

        return *this;
    }
}

Shadder& Shadder::loadFromMemory(const char* shadder)
{
    return loadFromMemory(&shadder,1);
}

Shadder& Shadder::loadFromMemory(const char** shadder,int num)
{
    glShaderSource(id,num,shadder, NULL);
    glCompileShader(id);

    check_compile_errors();

    return *this;
}

void Shadder::check_compile_errors()
{
    GLint success;

    glGetProgramiv(id, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        char infolog[513];
        glGetShaderInfoLog(id, 512, NULL, infolog);
        throw Shadder_Compile_Error(string("Error compiling shadder\n\n") + infolog);
    }
}

Shadder::~Shadder()
{
    glDeleteShader(id);
}
