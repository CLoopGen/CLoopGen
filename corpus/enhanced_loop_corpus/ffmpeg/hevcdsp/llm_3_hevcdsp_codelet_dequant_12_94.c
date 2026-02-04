#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd element first, then the odd positions
    int16_t *base = coeffs;
    int total = size * size;
    // Process even indices (stride of 2)
    for (int i = 0; i < total; i += 2) {
        base[i] = ((uint16_t)base[i]) << (-shift);
    }
    // Process odd indices (offset by 1, stride of 2)
    for (int i = 1; i < total; i += 2) {
        base[i] = ((uint16_t)base[i]) << (-shift);
    }
}
