
function Barrier(factory, x, y, w, h, color)
    return factory
        :begin("Barrier")
        :add_fixed_box_physic(x, y, w, h)
        :add_box_render(w, h, color)
        :build()
end