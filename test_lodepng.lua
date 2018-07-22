local lodepng = require "lodepng"

local result, width, height = lodepng.decode32_file("test\n")
if error then
    message = lodepng.error_text(error)
    print(message)
end