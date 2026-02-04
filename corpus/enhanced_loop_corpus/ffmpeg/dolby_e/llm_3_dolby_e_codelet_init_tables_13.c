#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using temporary array to change access pattern
    float temp[128];
    for (i = 0; i < 128; i++) {
        temp[i] = window[127 - i];  // Reverse copy into temp with consecutive access
    }
    for (i = 0; i < 128; i++) {
        window[128 + i] = temp[i];  // Consecutive write
    }
}
