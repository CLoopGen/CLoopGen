#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive forward access using a temporary array to reverse elements
    // We use a local buffer to read all elements consecutively, then write them back reversed
    float temp[128];
    
    // Copy original array into temporary storage
    for (i = 0; i < 128; i++) {
        temp[i] = pIn[i];
    }
    
    // Write back in reverse order: now each access is sequential in output
    for (i = 0; i < 128 / 2; i++) {
        pIn[i] = temp[128 - 1 - i];
        pIn[128 - 1 - i] = temp[i];
    }
}
