#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of 1, but backwards)
    for (dir = 3; dir >= 0; dir--)
        if (squaresize[dir] == j)
            break;
}
