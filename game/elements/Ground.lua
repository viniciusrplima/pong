
require "game.elements.Barrier"

function Ground(factory, width, height, color)
    local thickness = 0.1

    local left = Barrier(factory, -width / 2, 0, thickness, height, color)
    local right = Barrier(factory, width / 2, 0, thickness, height, color)
    Barrier(factory, 0, -height/2, width, thickness, color)
    Barrier(factory, 0, height/2, width, thickness, color)

    return left, right
end