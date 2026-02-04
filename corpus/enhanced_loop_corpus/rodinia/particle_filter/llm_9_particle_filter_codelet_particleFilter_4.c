#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int diameter;
extern int *disk;
extern int countOnes;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int x_start = 0, x_end = diameter;
int y_start, y_end;
for (x = x_start; x < x_end; x += 2) {
    y_start = 0;
    y_end = (x % 4 == 0) ? diameter : diameter / 2;
    for (y = y_start; y < y_end; y++) {
        if (disk[x * diameter + y] == 1)
            countOnes++;
        if ((x + 1) < x_end && disk[(x + 1) * diameter + y] == 1)
            countOnes++;
    }
}
}
