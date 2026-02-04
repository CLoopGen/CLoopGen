#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3 && j < 9; i++, j++) {
        x[k] *= 10;
        x[k] += 5;
        x[k] -= 2;
        k = (k + 1) % 128; // Modify k to access different array elements
    }
}
