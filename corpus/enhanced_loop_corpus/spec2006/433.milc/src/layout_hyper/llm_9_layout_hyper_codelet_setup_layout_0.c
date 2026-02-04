#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2, dir = 0; dir <= 3; dir += 2) {
        if (squaresize[dir] > j && squaresize[dir] % 4 == 0)
            j = squaresize[dir];
        j += (dir % 2) + 1;
    }
}
