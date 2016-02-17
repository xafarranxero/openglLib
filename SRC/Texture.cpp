#include "Texture.hpp"

using namespace JMT;


Texture& Texture::loadFromFile(const char* name)
{
    sf::Image image;
    image.loadFromFile(name);

    return loadFromImage(image);
}

Texture& Texture::loadFromMemory(const void* data,size_t size)
{
    sf::Image image;
    image.loadFromMemory(data,size);

    return loadFromImage(image);
}

Texture& Texture::loadFromImage(const sf::Image &image)
{
    bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WRAP_S);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WRAP_T);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FILTER_MIN);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FILTER_MAG);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,image.getSize().x,image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        glGenerateMipmap(GL_TEXTURE_2D);

    unbind();

    return *this;
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D,id);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D,0);
}

Texture::~Texture()
{
    glDeleteTextures(1,&id);
}
