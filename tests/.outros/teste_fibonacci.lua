-- TESTE COMPILADOR - Fibonacci

local n = read()

local a = 0
local b = 1

if n > 1 or n == 1 then
    print(a)
end

if n > 2 or n == 2 then
    print(b)
end

while n > 2 do
    temp = b
    b = b + a 
    a = temp

    print(b)

    n = n - 1
end