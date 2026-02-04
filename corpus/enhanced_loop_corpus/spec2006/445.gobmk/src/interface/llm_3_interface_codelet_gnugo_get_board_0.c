#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int b[19][19];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and fixed stride over 'board'
    // Access board with a constant stride pattern, traversing i and j in reverse order
    for (j = board_size - 1; j >= 0; j--)
        for (i = board_size - 1; i >= 0; i--)
            b[i][j] = board[(19 + 2) + i * (19 + 1) + j];
}
