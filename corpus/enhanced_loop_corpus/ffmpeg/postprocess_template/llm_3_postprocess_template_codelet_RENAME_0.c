#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int min;
extern int max;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *temp_p = p + 64; // Base pointer adjusted for reverse traversal
for (y = 1; y < 9; y++) {
    int x;
    for (x = 1; x < 9; x++) {
        uint8_t val = *(temp_p - (y * 8 + x)); // Consecutive reverse indexed access
        if (val > max)
            max = val;
        if (val < min)
            min = val;
    }
}
}
