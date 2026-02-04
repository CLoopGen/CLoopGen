#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (j = 0, dir = 0; dir < 4; dir++) {
        temp = squaresize[dir] + 1;
        if (temp > j && (temp % 2) == 1)
            j = temp;
    }
}
