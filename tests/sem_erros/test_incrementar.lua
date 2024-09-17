local res = 0

function incrementar()
    res = res + 1
end

function principal()
    incrementar()
    incrementar()
    incrementar()
    print(res)
end

principal()