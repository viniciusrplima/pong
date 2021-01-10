
require "game.config.global"
require "game.scene"

local scene = Scene("Pong", Config.SCENE_WIDTH, Config.SCENE_HEIGHT)

build_scene(scene)


function rebuild()
    scene:reset()
    
    if Config.THEME == "led" then
        Config.THEME = "retro"
    elseif Config.THEME == "retro" then
        Config.THEME = "standard"
    else
        Config.THEME = "led"
    end
    
    build_scene(scene)
end

--[[
    Must be safe because when we call the rebuild
    the engine destroy all references to functions on Lua. 
    That is, this function will destroy itself.
]]
scene:safe_on_key_pressed("r", rebuild)

