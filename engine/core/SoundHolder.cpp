#include "SoundHolder.h"

sf::SoundBuffer &SoundHolder::getSoundBuffer(const std::string &filename)
{
    auto found = _sounds.find(filename);

    if (found == _sounds.end())
    {
        std::unique_ptr<sf::SoundBuffer> sound(new sf::SoundBuffer);
        sound->loadFromFile(filename);
        _sounds.insert(std::make_pair(filename, std::move(sound)));

        return *_sounds.find(filename)->second;
    }
    else
        return *found->second;
}

void SoundHolder::clear()
{
    _sounds.clear();
}

std::map<std::string, std::unique_ptr<sf::SoundBuffer>> SoundHolder::_sounds;