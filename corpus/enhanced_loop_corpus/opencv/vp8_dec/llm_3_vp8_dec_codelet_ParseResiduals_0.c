#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal
    for (i = 16 * 16 - 16; i >= 0; i -= 16)
        dst[i] = dc0;
}
