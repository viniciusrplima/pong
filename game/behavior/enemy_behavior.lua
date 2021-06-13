
-- setup enemy behavior
function enemy_behavior(ball)

    return function (entity)

        physics = PhysicManipulator()
    
        local ball_pos = physics:get_position(ball)
        local enemy_pos = physics:get_position(entity)
        
        if ball_pos.y > enemy_pos.y then
            physics:change_velocity(entity, 0, Config.PLATFORM_SPEED)
        else
            physics:change_velocity(entity, 0, -Config.PLATFORM_SPEED)
        end
    end

end