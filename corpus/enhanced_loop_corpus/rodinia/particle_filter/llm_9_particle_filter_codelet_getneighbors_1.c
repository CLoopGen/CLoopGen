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
for (x = 1; x < diameter - 1; x++) {
    for (y = 1; y < diameter - 1; y++) {
        int idx = x * diameter + y;
        if (se[idx] && (x >= center || y < center)) {
            neighbors[neighY * 2] = y - center;
            neighbors[neighY * 2 + 1] = x - center;
            neighY += 1;
        }
    }
}
}
