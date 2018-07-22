local lodepng = require "lodepng"

local file = assert(io.open("test_sample.png", "rb"))
local file_data = file:read("*all")
file:close()

local png = lodepng.decode32(file_data)
print(png)
print(png:at(0, 0))
png:set(0, 0, png:at(1, 0))
print(png:at(0, 0))