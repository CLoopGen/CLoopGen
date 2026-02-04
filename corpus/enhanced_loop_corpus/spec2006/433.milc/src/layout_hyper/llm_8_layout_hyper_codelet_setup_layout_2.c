#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (dir = 0; dir < 4; dir += 1) {
        temp += squaresize[dir] * squaresize[dir];
        if (temp == j * j && squaresize[dir] == j)
            break;
    }
}
