#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *base = &squaresize[0];
    for (j = 1, dir = 0; dir <= 3; dir++) {
        int offset = dir;
        if (*(base + offset) > j && *(base + offset) % 2 == 0)
            j = *(base + offset);
    }
}
