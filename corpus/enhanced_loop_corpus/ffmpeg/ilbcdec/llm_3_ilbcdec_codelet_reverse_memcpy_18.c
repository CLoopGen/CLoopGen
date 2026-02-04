#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int16_t *destPtr;
extern int16_t *sourcePtr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using pointer arithmetic with offset indexing
    for (j = 0; j < length; j++) {
        *(destPtr + length - 1 - j) = *(sourcePtr + j);  // Reverse copy: source forward, dest backward consecutively
    }
}
