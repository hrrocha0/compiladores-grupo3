-- Variáveis
local x = read()
local y = read()
local res = 0

-- Módulo 1: Função de somar
function somar()
    res = x + y
end

-- Módulo 2: Função de multiplicar
function multiplicar()
    res = x * y
end

-- Módulo 3: Função principal que chama as outras
function principal()
    -- Chamando as sub-rotinas
    somar()
    print(res)
    multiplicar();
    print(res)
end

-- Executando o programa principal
principal()
