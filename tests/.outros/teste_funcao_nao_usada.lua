local x = 10
local y = 5
local res = 0

-- Função de somar (não utilizada)
function somar()
    res = x + y
end

-- Função de multiplicar (usada no programa)
function multiplicar()
    res = x * y
end

-- Função principal que chama apenas a função de multiplicar
function principal()
    multiplicar();
    print(res);
end

-- Executando o programa principal
principal()
