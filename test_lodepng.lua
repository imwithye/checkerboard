local lodepng = require "lodepng"

png = lodepng.decode_file("test_png.png")

for x = 0, png.width do
    for y = 0, png.height do
        if (x % 2 == 0 and y % 2 == 0) or (x % 2 == 1 and y % 2 == 1) then
            png:set(x, y, 0, 0, 0, 0)
        end
    end
end
png:encode_file("test_result_checkerboard.png")

for x = 0, png.width do
    for y = 0, png.height do
        if (x % 2 == 0 and y % 2 == 0) or (x % 2 == 1 and y % 2 == 1) then
            r1, g1, b1, a1 = png:at(x - 1, y)
            r2, g2, b2, a2 = png:at(x, y - 1)
            r3, g3, b3, a3 = png:at(x + 1, y)
            r4, g4, b4, a4 = png:at(x, y + 1)
            r = math.floor((r1 + r2 + r3 + r4) / 4)
            g = math.floor((g1 + g2 + g3 + g4) / 4)
            b = math.floor((b1 + b2 + b3 + b4) / 4)
            a = math.floor((a1 + a2 + a3 + a4) / 4)
            png:set(x, y, r, g, b, a)
        end
    end
end
png:encode_file("test_result_checkerboard_rendering.png")

png:dispose()
