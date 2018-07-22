local lodepng = require "lodepng"

local png, error = lodepng.decode_file("test_sample.png")
print(png)
print(error)
print(png:at(0, 0))
png:set(0, 0, png:at(1, 0))
print(png:at(0, 0))

png:encode_file("test_result_sample.png")

png:dispose()