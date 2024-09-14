-- TESTE COMPILADOR - Fatorial

local n = read()
local i = 1

while n > 0 do
    i = n * i
    n = n - 1
end

print(i)