require "game.config.sprites"

function Platform(factory, x, y, w, h, behavior)
    behavior = behavior or function() end

    if Config.THEME == "retro" then
        return factory
            :begin("Platform")
            :add_box_physic(x, y, w, h)
            :add_sprite_render(w * 1.2, h * 1.1, Sprites.PLATFORM_RETRO)
            :add_behavior(behavior)
            :build()
    elseif Config.THEME == "led" then
        platform_colors = {
            Sprites.PLATFORM_LED_BLUE, 
            Sprites.PLATFORM_LED_RED, 
            Sprites.PLATFORM_LED_PINK, 
            Sprites.PLATFORM_LED_GREEN, 
        }

        index = math.random(#platform_colors)
        sprite = platform_colors[index]

        return factory
            :begin("Platform")
            :add_box_physic(x, y, w, h)
            :add_sprite_render(w * 5.5, h * 1.5, sprite)
            :add_behavior(behavior)
            :build()
    else
        return factory
            :begin("Platform")
            :add_box_physic(x, y, w, h)
            :add_box_render(w, h, "blue")
            :add_behavior(behavior)
            :build()
	end
end
