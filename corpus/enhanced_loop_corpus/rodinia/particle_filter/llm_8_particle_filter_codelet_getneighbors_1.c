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
int temp_x, temp_y;
for (x = 0; x < diameter * diameter; x++) {
    temp_y = x % diameter;
    temp_x = x / diameter;
    if (se[temp_x * diameter + temp_y]) {
        neighbors[neighY * 2] = temp_y - center;
        neighbors[neighY * 2 + 1] = temp_x - center;
        neighY++;
    }
}
}
