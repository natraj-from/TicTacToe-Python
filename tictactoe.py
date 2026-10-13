board="""
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

"""
x=[]
o=[]
print(board)
def win(a,b):
    win_combo=[ ['1','2','3'],['4','5','6'],['7','8','9'],['1','4','7'],['5','2','8'],['6','9','3'],['1','5','9'],['5','7','3'] ]
    for i in win_combo:
        if all(pos in a for pos in i) :
            print(b," Wins")
            return 1

def move(name):
    for attempt in range (2):
        move=input(name+" Move: ")
        if move in list("123456789") and move not in x and move not in o :
            return move
        if attempt==0:
            print("\nInvalid move try again\n")
            print(board)
    print("\nInvaild move again "+name+"'s chance is skipped.\n")
    print(board)
    return None

while (len(x)+len(o)<9):
    xmove=move("X")
    if xmove is not None:
        x.append(xmove)
        newboard=board.replace(xmove,"X")
        board=newboard
        print(board)
    if win(x,"X"):
        break

    if (len(x)+len(o)==9):
        print("Draw")
        break
    omove=move("O")
    if omove is not None:
        o.append(omove)
        newboard=board.replace(omove,"O")
        board=newboard
        print(board)
    if win(o,"O"):
        break
    if (len(x)+len(o)==9):
            print("Draw")
            break