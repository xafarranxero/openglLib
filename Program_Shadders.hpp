#ifndef PROGRAM_SHADDERS_H
#define PROGRAM_SHADDERS_H

#include <string>
#include "glheaders.hpp"
#include "Shadder.hpp"

#include "NoCopyable.hpp"
#include <vector>

namespace JMT
{
    class Shadder;

    class Program_Shadders : public NoCopyable
    {
        public:
            Program_Shadders();

            Program_Shadders(const char *vs,  const char* fs):Program_Shadders()
            {
                JMT::Shadder vss(GL_VERTEX_SHADER,vs,true),fss(GL_FRAGMENT_SHADER,fs,true);

                append(vss);
                append(fss);

                link();
            }

            Program_Shadders(JMT::Shadder **sh, int n):Program_Shadders()
            {
                for(int i = 0; i<n; i++)
                {
//                    append(sh[i]->getId());
                    glAttachShader(id,sh[i]->getId());
                }
                link();
            }

            GLint GetUniformLocation(const char* c)
            {
                return glGetUniformLocation(id,c);
            }

            void append(Shadder& referencia);

            void link();
            void use();

            ~Program_Shadders();
        protected:
        private:

            void check_shadder_link();
    };

    struct Program_Shadders_Error : public std::exception
    {
        std::string log_text;

        Program_Shadders_Error(const std::string text) : log_text(text) {}

        virtual const char* what() const throw() { return log_text.c_str();}
    };

    struct Program_Shadders_Link_Error : public Program_Shadders_Error
    {
        Program_Shadders_Link_Error(const std::string text) : Program_Shadders_Error(text){}
    };
}

#endif // PROGRAM_SHADDERS_H
