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
    for (int i = 0; i < 1; i++) {
        for (y = 0; y < diameter; y++) {
            if (se[x * diameter + y]) {
                neighbors[neighY * 2] = (int)(y - center);
                neighbors[neighY * 2 + 1] = (int)(x - center);
                neighY++;
            }
        }
    }
}
}
