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
for (k = 0; k < 4; k++) {
    if (board[pos + delta[k]] == 3)
        continue;
    neighbors |= board[pos + delta[k]];
}
}
