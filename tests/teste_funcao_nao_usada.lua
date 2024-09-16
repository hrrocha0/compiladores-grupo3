-- Função de somar (não utilizada)
function somar(a, b)
    return a + b
end

-- Função de multiplicar (usada no programa)
function multiplicar(a, b)
    return a * b
end

-- Função principal que chama apenas a função de multiplicar
function principal()
    local x = 10
    local y = 5

    -- Chamando apenas a função multiplicar
    print("Multiplicação: ", multiplicar(x, y))
end

-- Executando o programa principal
principal()
