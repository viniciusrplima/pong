#include "SoundManipulator.h"

SoundManipulator::SoundManipulator()
{
}

SoundManipulator::~SoundManipulator()
{
}

void SoundManipulator::play(const std::string &filename)
{
    (new sf::Sound(SoundHolder::getSoundBuffer(filename)))->play();
}

void SoundManipulator::playInLoop(const std::string &filename)
{
    // TODO
}