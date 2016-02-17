#ifndef BUFFER_H
#define BUFFER_H

#include "glheaders.hpp"
#include "NoCopyable.hpp"

namespace JMT
{

    class Buffer : public NoCopyable
    {
        public:
            Buffer();

            void bind(GLenum type);
            void unbind();

            void bufferData(void* data,size_t size,GLenum type_of_draw = GL_STATIC_DRAW);

            void* mapBuffer(GLenum access);
            GLboolean unmapBuffer();

            ~Buffer();
        protected:
        private:
            GLenum type;
    };
}
#endif // BUFFER_H
