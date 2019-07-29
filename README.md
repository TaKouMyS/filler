# Filler

Filler is a game, where two players / algorithm are fighting on a map.

A virtual machine organizes the game :
    
   - calls the players alternatively
   - give each a random piece
    
On each turn, the current player have to put his piece on the map, and try to bother the ennemy. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).

The game appears on the standard input.

The aim of the game is to put more pieces on the map than the ennemy.
Once one make a mistake or cannot place his piece, his turn ends and the player will not play anymore. Alowing the oponent to play freely until the board is full or he cannot play.

# Algorythm

The algorythm uses a heatmap. For each turn, after reading the map and the piece given, a heatmap will be generated.
The heat map give values to each of the board's square as following : 

   - my pieces are graded -1
   - oponent's pieces are graded -2
   - pieces surrounding oponent's pieces are graded 1
   - pieces surrounding graded 1 are graded 2, etc...
    
This allows to know which squares are close to oponent's pieces.

Once the heatmap created, it iterates the map and try to place the piece. Will be played the valid coordonates with the lowest heatscore.

# Installation

```
    make
```

# Run

To launch the game, you have to launch the virtual machine in the ressource directory and give it : 
 - a map and  2 players as follow : 

```
    ./filler_vm -f [MAP] -p1 ./[PLAYER] -p2 ./[PLAYER]
```

