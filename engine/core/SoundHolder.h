#include <SFML/Audio/SoundBuffer.hpp>
#include <memory>
#include <map>
#include <string>

#ifndef _SOUND_HOLDER_H_
#define _SOUND_HOLDER_H_

class SoundHolder
{
public:
    static sf::SoundBuffer &getSoundBuffer(const std::string &);
    static void clear();

private:
    static std::map<std::string, std::unique_ptr<sf::SoundBuffer>> _sounds;
};

#endif