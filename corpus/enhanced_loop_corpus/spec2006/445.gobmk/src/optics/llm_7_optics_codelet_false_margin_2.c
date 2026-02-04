#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int pos;
extern int neighbors;
extern int k;
extern int delta[8];
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Intersection local_board[8];
    for (k = 0; k < 4; k++)
        local_board[k] = board[pos + delta[k]];
    for (k = 0; k < 4; k++)
        if (local_board[k] != 3)
            neighbors |= local_board[k];
}
