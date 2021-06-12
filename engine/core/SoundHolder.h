#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <memory>
#include <map>
#include <string>
#include <list>

#ifndef _SOUND_HOLDER_H_
#define _SOUND_HOLDER_H_

class SoundHolder
{
public:
    static sf::SoundBuffer &getSoundBuffer(const std::string &);
    static void clear();
    static void play(const std::string&);
    static void removeStoppedSounds();

private:
    static std::map<std::string, std::unique_ptr<sf::SoundBuffer>> _sounds;
    static std::list<std::unique_ptr<sf::Sound>> _playingSounds;
};

#endif