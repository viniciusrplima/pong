
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