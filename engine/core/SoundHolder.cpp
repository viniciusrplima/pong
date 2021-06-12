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

void SoundHolder::play(const std::string& filename) {
    std::unique_ptr<sf::Sound> sound(new sf::Sound);
    sound->setBuffer(getSoundBuffer(filename));
    sound->play();
    _playingSounds.push_front(std::move(sound));
}

void SoundHolder::removeStoppedSounds() {
    std::vector<std::list<std::unique_ptr<sf::Sound>>::iterator> soundsToRemove;

    for (auto iter = _playingSounds.begin(); iter != _playingSounds.end(); iter++) {
        if ((*iter)->getStatus() == sf::SoundSource::Stopped) {
            soundsToRemove.push_back(iter);
        }
    }

    for (auto sound : soundsToRemove) {
        _playingSounds.erase(sound);
    }
}

std::map<std::string, std::unique_ptr<sf::SoundBuffer>> SoundHolder::_sounds;
std::list<std::unique_ptr<sf::Sound>> SoundHolder::_playingSounds;