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
    if (!(vertically_symmetric || horizontally_symmetric || diagonally_symmetric)) return;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            int idx1 = (19 + 2) + i * (19 + 1) + j;
            int idx2 = (19 + 2) + i * (19 + 1) + (board_size - 1 - j);
            int idx3 = (19 + 2) + (board_size - 1 - i) * (19 + 1) + j;
            int idx4 = (19 + 2) + (board_size - 1 - j) * (19 + 1) + (board_size - 1 - i);
            if (horizontally_symmetric && board[idx1] != board[idx2])
                horizontally_symmetric = 0;
            if (vertically_symmetric && board[idx1] != board[idx3])
                vertically_symmetric = 0;
            if (diagonally_symmetric && board[idx1] != board[idx4])
                diagonally_symmetric = 0;
        }
        if (!horizontally_symmetric && !vertically_symmetric && !diagonally_symmetric)
            break;
    }
}
