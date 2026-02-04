#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 2, 1, 3}; // shuffled access order
    for (j = 1, dir = 0; dir <= 3; dir++) {
        int idx = indices[dir];
        if (squaresize[idx] > j && squaresize[idx] % 2 == 0)
            j = squaresize[idx];
    }
}
