#ifndef TEXTURA_H
#define TEXTURA_H
#include "NoCopyable.hpp"
#include "glheaders.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SOIL/SOIL.h>

namespace JMT
{
    class Texture : public NoCopyable
    {
        public:
            Texture():Texture(sf::Vector2i(GL_REPEAT,GL_REPEAT),sf::Vector2i(GL_LINEAR,GL_LINEAR)){}

            Texture(const sf::Vector2i &conf, const sf::Vector2i &conf2)
            {
                glGenTextures(1,&id);
                setConf(conf,conf2);
            }

            void setConf(const sf::Vector2i &conf, const sf::Vector2i &conf2)
            {
                WRAP_S = conf.x;
                WRAP_T = conf.y;

                FILTER_MIN = conf2.x;
                FILTER_MAG = conf2.y;
            }

            Texture& loadFromFile(const char* name);
            Texture& loadFromImage(const sf::Image&);
            Texture& loadFromMemory(const void*,size_t);

            void bind();

            void unbind();
            ~Texture();
        protected:
        private:
            GLint WRAP_S,WRAP_T,FILTER_MAG,FILTER_MIN;
    };

}

#endif // TEXTURA_H
