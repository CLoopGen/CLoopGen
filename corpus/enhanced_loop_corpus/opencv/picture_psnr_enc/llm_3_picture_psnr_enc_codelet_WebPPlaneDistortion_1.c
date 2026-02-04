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
    // Variant 2: Strided memory access pattern - process every second row and column
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
        }
    }
}
