local lodepng = require "lodepng"

local png, error_message = lodepng.decode_file("test_sample.png")
print(png, error_message)
print(png:at(0, 0))
png:set(0, 0, png:at(1, 0))
print(png:at(0, 0))
png:encode_file("test_result_sample.png")
png:dispose()