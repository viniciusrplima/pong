#include "../GuiComponent.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "../../TexturesHolder.h"

#ifndef _DISPLAY_COMPONENT_H_
#define _DISPLAY_COMPONENT_H_

class DisplayComponent : public GuiComponent
{
public:
    DisplayComponent(const std::vector<std::string> &, float, float);
    ~DisplayComponent();

    void render(sf::RenderTarget &, sf::RenderStates);
    void setValues(int a, int b);

private:
    void drawNumber(int, sf::RenderTarget &, sf::RenderStates);

private:
    std::vector<std::string> _texturesFiles;
    std::vector<sf::Sprite> _numberSprites;
    bool _loaded;
    float _size;
    float _distanceBetween;
    int _numA;
    int _numB;
};

#endif