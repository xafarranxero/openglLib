#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "NoCopyable.hpp"
#include "glheaders.hpp"

namespace JMT
{

    class Vertex_Array : public NoCopyable
    {
        public:
            Vertex_Array();

            void bind();
            void unbind();

            ~Vertex_Array();
        protected:
        private:
    };

}
#endif // VERTEX_ARRAY_H
