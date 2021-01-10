
require "game.config.global"
require "game.config.sprites"

function Display(factory, size, distance)
    return factory:create_display(
        NumberSprites, 
        size, 
        distance, 
        0,
        -200 
    )
end