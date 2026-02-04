#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using pointer arithmetic for direct memory access
    J12SAMPLE *ptr = table12 + 2048;
    int count = 2 * (4095 + 1) - 2048;
    for (i = 0; i < count; i++) {
        ptr[i] = 4095;
    }
}
