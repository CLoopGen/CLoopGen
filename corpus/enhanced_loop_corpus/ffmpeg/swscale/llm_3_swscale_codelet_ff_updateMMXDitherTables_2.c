#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset-based indirect read using an index array simulation
    int offset = 1;
    for (; i < vLumFilterSize; i++) {
        int read_index = i - offset;
        if (read_index >= 0) {
            tmpY[i] = tmpY[read_index];
        } else {
            tmpY[i] = NULL; // Safe fallback for out-of-bounds
        }
    }
}
