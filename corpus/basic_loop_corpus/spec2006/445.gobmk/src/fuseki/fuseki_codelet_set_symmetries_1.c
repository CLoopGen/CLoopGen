#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int horizontally_symmetric;
extern int vertically_symmetric;
extern int diagonally_symmetric;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < board_size && (vertically_symmetric || horizontally_symmetric || diagonally_symmetric); i++)
    for (j = 0; j < board_size; j++) {
        if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (i) * (19 + 1) + (board_size - 1 - j))])
            horizontally_symmetric = 0;
        if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (board_size - 1 - i) * (19 + 1) + (j))])
            vertically_symmetric = 0;
        if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (board_size - 1 - j) * (19 + 1) + (board_size - 1 - i))])
            diagonally_symmetric = 0;
    }

}
