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
    int temp_neighY = neighY;
    for (x = 0; x < diameter; x++) {
        for (y = 0; y < diameter; y++) {
            if (se[x * diameter + y]) {
                neighbors[temp_neighY * 2] = (int)(y - center);
                neighbors[temp_neighY * 2 + 1] = (int)(x - center);
                temp_neighY++;
            }
        }
    }
    neighY = temp_neighY;
}
