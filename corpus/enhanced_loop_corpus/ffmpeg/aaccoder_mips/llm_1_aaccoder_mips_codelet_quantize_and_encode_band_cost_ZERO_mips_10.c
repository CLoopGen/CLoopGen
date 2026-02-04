#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size <= 0) return;
    for (i = 0; i < size; i++) {
        for (int offset = 0; offset < 4 && i + offset < size; offset += 1) {
            out[i + offset] = 0.F;
        }
        i += 3; // Maintain approximate original step to avoid overlap
    }
}
