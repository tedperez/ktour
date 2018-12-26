
#=


function occupySquare(nextSquare, currBoard, currDepth)
    #=
    #
    if currBoard[nextSquare]
    end
    #
    =#
end

=#


rows = 5
cols = 5


maxSquares = rows * cols
maxDepth   = maxSquares


ctr = 0
ctr = convert(Int8, ctr)


# print(ctr)
print(typeof(ctr))


println()
println()


#board = [0*0 for i in 1:rows, j in 1:cols] 
board = Matrix{Int8}(undef,rows,cols)


jumpSquares = []


println("jumpSquares: ", jumpSquares)
println(typeof(jumpSquares))

#=
println(board)
println(typeof(board))
println()
println()
=#

println()
println()

println("board:")
println()


for i in 1:rows
    for j in 1:cols
        global ctr += 1
        board[i,j] = ctr
    end
    println(board[i,:])
end
println(typeof(board))

println()
println()


#=
#
#  generate valid squares to jump to
#
=#

@async for i in 1:rows

    for j in 1:cols

        validsq = []
        
        if i + 2 <= rows

            if j + 1 <= cols
        
                # println(board[i+2,j+1])
		        push!(validsq,board[i+2,j+1])

            end

            if j - 1 >= 1

                push!(validsq,board[i+2,j-1])

            end
	
        end

        if i - 2 >= 1

            if j + 1 <= cols

                push!(validsq,board[i-2,j+1])

            end

            if j - 1 >= 1

                push!(validsq,board[i-2,j-1])

            end

        end

        if j + 2 <= cols

            if i + 1 <= rows

                push!(validsq,board[i+1,j+2])

            end

            if i - 1 >= 1

                push!(validsq,board[i-1,j+2])

            end

        end

        if j - 2 >= 1

            if i + 1 <= rows

                push!(validsq,board[i+1,j-2])

            end

            if i - 1 >= 1

                push!(validsq,board[i-1,j-2])

            end

        end

	push!(jumpSquares,validsq)


    end

end


println("jumpSquares:")
println()
println()

ctr = 0
for i in jumpSquares
    global ctr += 1
    println(ctr,i)

end

println()
println()




# 

#println(nprocs())
println
println

j = rows * cols


#=
 #
 #  time to check out an "experimental" parallel programming feature
 #
 =#

@distributed for k in 1:10^4

    @async for i in 1:j 
        springBoard = jumpSquares[i]
        # println(i, springBoard)
    end

end


#=
 #
 #
 =#


#=
#
#  find routes
#

Threads.@threads for k in 1:maxSquares

    Threads.@threads for l in jumpSquares

end

=#

println("maxSquares: ", maxSquares)
println
println


@async for i in 1:maxSquares

    println(jumpSquares[i])

end
