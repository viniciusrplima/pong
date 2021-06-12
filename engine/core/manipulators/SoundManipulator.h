#include <SFML/Audio.hpp>
#include <list>
#include <memory>
#include <thread>
#include <unistd.h>
#include "../SoundHolder.h"

#ifndef _SOUND_MANIPULATOR_H_
#define _SOUND_MANIPULATOR_H_

class SoundManipulator
{
private:


public:
    SoundManipulator();
    ~SoundManipulator();

    void play(const std::string &);
    void playInLoop(const std::string &);
};

#endif
