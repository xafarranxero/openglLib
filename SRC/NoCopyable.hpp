#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H

#include "glheaders.hpp"

namespace JMT
{

    class NoCopyable
    {
        protected:
            GLuint id;
        public:
            NoCopyable(){}
            NoCopyable(const NoCopyable&) = delete;
            NoCopyable& operator=(NoCopyable&) = delete;

            GLuint getId() const
            {
                return id;
            }

            operator GLuint() const
            {
                return getId();
            }

    };
}
#endif // NOCOPYABLE_H
