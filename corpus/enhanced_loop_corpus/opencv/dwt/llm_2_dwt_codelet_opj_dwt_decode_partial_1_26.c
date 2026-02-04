#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access with factor 2, use consecutive elements by reindexing
    // Original: a[2*i], a[2*(i+1)], a[2*i + 1]
    // New: Access a[i], a[i+1], a[i+2] consecutively to improve cache locality
    OPJ_INT32 *base = a + 2; // Shift base to simulate offset
    for (; i < i_max; i++) {
        base[i] += (base[i - 1] + base[i + 1]) >> 1;
    }
}
