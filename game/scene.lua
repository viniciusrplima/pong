
require "game.elements.Ball"
require "game.elements.Ground"
require "game.elements.Platform"
require "game.elements.Display"

require "game.config.sounds"
require "game.utils.conversions"
require "game.utils.colors"

require "game.controls"
require "game.behavior.enemy_behavior"

function build_scene(scene)

    --[[
        BUILDING SCENE
    ]]--

    -- creating engine manipulators
    local factory = EntityFactory(scene)
    local physics = PhysicManipulator()
    local audio = SoundManipulator()

    -- create ball
    local ball = Ball(factory, 0.12)

    -- create player platform
    local player = Platform(
        factory, 
        to_scene(-Config.SCENE_WIDTH/2) + 0.1, 
        0, 0.1, 1.5
    )

    -- create enemy platform
    local enemy = Platform(
        factory, 
        to_scene(Config.SCENE_WIDTH/2), 
        0, 0.1, 1.5, 
        enemy_behavior(ball)
    )

    -- limit the scene like a jail
    local left_side, right_side = Ground(
        factory, 
        to_scene(Config.SCENE_WIDTH), 
        to_scene(Config.SCENE_HEIGHT), 
        Color.TRANSPARENT
    )

    -- create score display
    display = Display(factory, 70, 240)

    -- setup player controls
    platform_control(scene, player)

    -- launch ball
    physics:change_velocity(ball, 10.0, 2.0)

    --[[
        SETUP GAME RULES        
    ]]--

    -- players scores
    local score_a = 0
    local score_b = 0

    -- function to show score every update
    function display_score() 
        display:set_values(score_a, score_b) 
    end

    -- collision on left side barrier
    physics:on_collision(left_side, function(kind) 
        if kind == "Ball" then 
            score_b = score_b + 1
            display_score()
        end
    end)

    -- collision on right side barrier
    physics:on_collision(right_side, function(kind)
        if kind == "Ball" then 
            score_a = score_a + 1
            display_score()
        end
    end)

    -- play sound when ball collide
    physics:on_collision(ball, function()
        audio:play(Sounds.BOUND_8BIT)
    end)

    -- quit when press escape key
    scene:on_key_pressed("esc", function() scene:destroy() end)
end
