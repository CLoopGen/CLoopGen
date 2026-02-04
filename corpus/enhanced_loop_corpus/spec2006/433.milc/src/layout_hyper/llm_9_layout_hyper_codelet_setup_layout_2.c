#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dir = 0; dir <= 7; dir++) {
        int index = dir % 4;
        if (squaresize[index] == j) {
            if ((j & 1) == 0 || dir > 4)
                break;
        }
    }
}
