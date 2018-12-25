#=

julia programming language code to find all routes for a given board of x,y square

=#

@everywhere jump(fromSquare, currBoard, currDepth) {

  @dsitirbuted for nextSquare in fromSquares
    if nextSquare isNotOccupied {
      currDepth += 1
      
      fromSquares = jumpSquares[nextSquare
      currBoard[nextSquare] = currDepth
      
      jump(fromSquare, currBoard, currDepth)

      if currDepth >+ maxDepth {
        global totalSolutions +=1
        println(currBoard)
      }
    }
  }
  
  @distributed for fromSquares in board
  
    pmap(jump, fromSquares)
    end
    println(totalSolutions)
    
    
