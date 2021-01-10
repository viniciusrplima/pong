#include "DisplayComponent.h"
#include "../../utils/InvalidNumberOfSpritesException.h"

DisplayComponent::DisplayComponent(
    const std::vector<std::string> &textures,
    float size,
    float distance)
    : _texturesFiles(),
      _size(size),
      _distanceBetween(distance),
      _loaded(false),
      _numA(0),
      _numB(0)
{
    if (textures.size() != 10)
        throw new InvalidNumberOfSpritesException("display requires 10 sprites");

    _texturesFiles = textures;
}

DisplayComponent::~DisplayComponent()
{
}

void DisplayComponent::render(sf::RenderTarget &target, sf::RenderStates states)
{
    if (!_loaded)
    {
        for (auto file : _texturesFiles)
        {
            sf::Sprite sprite(TexturesHolder::getTexture(file));
            _numberSprites.push_back(sprite);
        }
        _loaded = true;
    }

    states.transform.translate(-_distanceBetween / 2, 0);
    drawNumber(_numA, target, states);
    states.transform.translate(_distanceBetween, 0);
    drawNumber(_numB, target, states);
}

void DisplayComponent::setValues(int a, int b)
{
    _numA = a;
    _numB = b;
}

void DisplayComponent::drawNumber(
    int number,
    sf::RenderTarget &target,
    sf::RenderStates states)
{

    if (number == 0)
    {
        auto sprite = _numberSprites[0];
        auto texSize = sprite.getTexture()->getSize();

        float scale = _size / texSize.y;

        // centralize sprite
        states.transform.translate(-((float)texSize.x / texSize.y) * _size / 2, -_size / 2);
        states.transform.scale(scale, scale);
        target.draw(sprite, states);
    }
    else
    {
        int num = number;
        int numDigits = -1;
        while (num > 0)
        {
            numDigits++;
            num /= 10;
        }

        float offset = (_size * numDigits) / 2;
        while (number > 0)
        {
            int digit = number % 10;
            number /= 10;

            auto sprite = _numberSprites[digit];
            auto texSize = sprite.getTexture()->getSize();

            sf::RenderStates digitStates(states);
            float scale = _size / texSize.y;
            digitStates.transform.translate(offset, 0);

            // centralize sprite
            digitStates.transform.translate(-((float)texSize.x / texSize.y) * _size / 2, -_size / 2);

            digitStates.transform.scale(scale, scale);
            target.draw(sprite, digitStates);

            offset -= _size;
        }
    }
}
