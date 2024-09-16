-- Módulo 1: Função de somar
function somar(a, b)
    return a + b
end

-- Módulo 2: Função de multiplicar
function multiplicar(a, b)
    return a * b
end

-- Módulo 3: Função principal que chama as outras
function principal()
    local x = 10
    local y = 5

    -- Chamando as sub-rotinas
    print("Soma: ", somar(x, y))
    print("Multiplicação: ", multiplicar(x, y))
end

-- Executando o programa principal
principal()
