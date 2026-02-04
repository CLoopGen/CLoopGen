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
    int local_offset;
    for (x = 0; x < diameter; x++) {
        for (y = 0; y < diameter; y++) {
            if (se[x * diameter + y]) {
                local_offset = neighY * 2;
                neighbors[local_offset] = (int)(y - center);
                neighbors[local_offset + 1] = (int)(x - center);
                neighY++;
            }
        }
    }
}
