local lodepng = require "lodepng"

local file = assert(io.open("test_png.png", "rb"))
local file_data = file:read("*all")
file:close()

local png = lodepng.decode32(file_data)
print(png)