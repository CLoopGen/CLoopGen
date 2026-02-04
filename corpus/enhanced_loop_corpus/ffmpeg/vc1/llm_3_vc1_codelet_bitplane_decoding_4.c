#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < stride * height; x++) {
        int index = (x / stride) * stride + (stride - 1 - (x % stride)); // Reverse access within each row
        planep[index] = !planep[index];
    }
}
