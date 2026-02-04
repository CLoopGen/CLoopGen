#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            // Perform multiple arithmetic operations per iteration
            i = x + y * width;
            j = (i * i + 3 * i + 1) % 1000;
            i = (i + j) / 2;
        }
    }
}
