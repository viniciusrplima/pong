#include "SoundManipulator.h"

SoundManipulator::SoundManipulator()
{
}

SoundManipulator::~SoundManipulator()
{
}

void SoundManipulator::play(const std::string &filename)
{
    SoundHolder::play(filename);
}

void SoundManipulator::playInLoop(const std::string &filename)
{
    // TODO
}
