#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int i;
extern int32_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    int total_elements = w * h;
    for (i = total_elements - 1; i >= 0; i--) {
        data[i] = (data[i] + ((1LL << 8) >> 1)) >> 8;
    }
}
