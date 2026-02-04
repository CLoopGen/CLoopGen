#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *y;
extern int i;
extern  int lut_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = lut_size - 1; i >= 0; i--) {
        y[i] = i;
    }
}
