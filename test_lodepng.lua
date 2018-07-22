local lodepng = require "lodepng"

png, error_message = lodepng.decode_file("test_sample.png")
print(png, error_message)
print(png:at(0, 0))
png:set(0, 0, png:at(1, 0))
print(png:at(0, 0))
png:encode_file("test_result_sample.png")
png:dispose()
print()

png = lodepng.decode_file("test_png.png")
for x = 0, png.width do
    for y = 0, png.height do
        if x % 2 == 0 then
            if y % 2 == 0 then
                png:set(x, y, 0, 0, 0, 0)
            end
        else
            if y % 2 == 1 then
                png:set(x, y, 0, 0, 0, 0)
            end
        end
    end
end
png:encode_file("test_result_png.png")
png:dispose()
