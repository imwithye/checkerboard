local string = require "string"
local lodepng = require "lodepng"

local result, width, height, error_code = lodepng.decode32_file("test_png.png")
if error_code ~= 0 then
    print("err: " .. lodepng.error_text(error_code))
    return
end
print(string.format("png width = %s, height = %s", width, height))