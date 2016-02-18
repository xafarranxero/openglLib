#ifndef SHADDER_H
#define SHADDER_H
#include <exception>
#include <string>

#include "glheaders.hpp"

#include "NoCopyable.hpp"

namespace JMT
{
    class Shadder : public NoCopyable
    {
        public:
            Shadder(GLuint type);
//            Shadder(GLuint type,const char* shadder);
            Shadder(GLuint type,const char* shadder[],int num);
            Shadder(GLuint type,const char* shadder,bool file = false):Shadder(type)
            {
                if(file)
                    loadFromFile(shadder);
                else
                    loadFromMemory(shadder);
            }

            Shadder& loadFromFile(const char* name);

            Shadder& loadFromMemory(const char* shadder);
            Shadder& loadFromMemory(const char** shadder,int num);

            ~Shadder();
        protected:
        private:
            GLuint type;

            void initialize(GLuint type);

            void check_compile_errors();
    };

    struct Shadder_Error : public std::exception
    {
        std::string log_text;

        Shadder_Error(const std::string text) : log_text(text) {}

        virtual const char* what() const throw() { return log_text.c_str();}
    };

    struct Shadder_Compile_Error : public Shadder_Error
    {
        Shadder_Compile_Error(const std::string text) : Shadder_Error(text) {}
    };


    struct Shadder_File_Not_Founded : public Shadder_Error
    {
        Shadder_File_Not_Founded(const std::string text) : Shadder_Error(text) {}
    };


}

#endif // SHADDER_H

