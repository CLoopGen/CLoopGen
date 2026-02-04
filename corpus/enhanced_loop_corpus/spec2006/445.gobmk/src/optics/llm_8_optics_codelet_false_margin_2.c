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
for (k = 0; k < 8; k += 2)
    if ((board[pos + delta[k]] != 3) && (board[pos + delta[k + 1]] != 3))
        neighbors |= (board[pos + delta[k]] | board[pos + delta[k + 1]]);
}
