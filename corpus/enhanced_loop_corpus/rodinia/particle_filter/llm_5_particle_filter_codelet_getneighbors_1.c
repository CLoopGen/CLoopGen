#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *se;
extern double *neighbors;
extern int x;
extern int y;
extern int neighY;
extern int center;
extern int diameter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < diameter; x++) {
    for (y = 0; y < diameter; y++) {
        int index = x * diameter + y;
        if (se[index] && neighY >= 0) {
            int offset = neighY * 2;
            neighbors[offset] = y - center;
            neighbors[offset + 1] = x - center;
            neighY++;
        }
    }
}
}
