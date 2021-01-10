
require "game.elements.Ball"
require "game.elements.Ground"
require "game.elements.Platform"
require "game.elements.Display"

require "game.config.sounds"
require "game.utils.conversions"

function build_scene(scene)

    -- set inputs to plaform control
    function platform_control(scene, platform)
        
        local physics = PhysicManipulator()

        scene:on_key_pressed("up", function()
            physics:change_velocity(platform, 0, Config.PLATFORM_SPEED)
        end)

        scene:on_key_pressed("down", function()
            physics:change_velocity(platform, 0, -Config.PLATFORM_SPEED)
        end)

        scene:on_key_released("up", function() 
            physics:change_velocity(platform, 0, 0)
        end)
        
        scene:on_key_released("down", function() 
            physics:change_velocity(platform, 0, 0)
        end)
    end

    local factory = EntityFactory(scene)
    local physics = PhysicManipulator()
    local audio = SoundManipulator()

    -- create ball
    local ball = Ball(factory, 0.12)

    -- create player platform
    local player = Platform(factory, 
                            to_scene(-Config.SCENE_WIDTH/2) + 0.1, 
                            0, 0.1, 1.5)

    function enemy_behavior(entity)
        local ball_pos = physics:get_position(ball)
        local enemy_pos = physics:get_position(entity)
        
        if ball_pos.y > enemy_pos.y then
            physics:change_velocity(entity, 0, Config.PLATFORM_SPEED)
        else
            physics:change_velocity(entity, 0, -Config.PLATFORM_SPEED)
        end
    end

    -- create enemy platform
    local enemy = Platform(factory, 
                           to_scene(Config.SCENE_WIDTH/2), 
                           0, 0.1, 1.5, 
                           enemy_behavior)

    -- limit the scene like a jail
    left_side, right_side = Ground(
        factory, 
        to_scene(Config.SCENE_WIDTH), 
        to_scene(Config.SCENE_HEIGHT), 
        "transparent")

    -- create score display
    display = Display(factory, 70, 240)

    -- setup player controls
    platform_control(scene, player)

    -- launch ball
    physics:change_velocity(ball, 10.0, 2.0)

    local score_a = 0
    local score_b = 0

    function display_score() display:set_values(score_a, score_b) end

    physics:on_collision(left_side, function(kind) 
        if kind == "Ball" then 
            score_b = score_b + 1
            display_score()
        end
    end)

    physics:on_collision(right_side, function(kind)
        if kind == "Ball" then 
            score_a = score_a + 1
            display_score()
        end
    end)

    physics:on_collision(ball, function()
        audio:play(Sounds.BOUND_8BIT)
    end)

    scene:on_key_pressed("esc", function() scene:destroy() end)
end
