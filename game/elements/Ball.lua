
require "game.config.global"
require "game.config.sprites"

function Ball(factory, radius) 
    if Config.THEME == "retro" then
        return factory
            :begin("Ball")
            :add_ball_physic(radius)
            :add_sprite_render(radius * 1.8, radius * 1.8, Sprites.BALL_RETRO)
            :build()
    elseif Config.THEME == "led" then
        return factory
            :begin("Ball")
            :add_ball_physic(radius)
            :add_sprite_render(radius * 4.5, radius * 4.5, Sprites.BALL_LED)
            :build()
    else
        return factory
            :begin("Ball")
            :add_ball_physic(radius)
            :add_ball_render(radius, "red")
            :build()
    end
end
