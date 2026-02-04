#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int cb_gain;
extern int cb_shift;
extern int cb_sign;
extern int cb_pos;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed order and stride of 4
    int stride = 4;
    int index = 0;
    int pos = cb_pos;
    int sign = cb_sign;
    // Process the same logic but write into vector with strided pattern starting from high index
    for (i = 0; i < 8; i += 2) {
        offset = ((pos & 7) << 3) + cb_shift + i;
        // Map logical index i to physical strided location in reverse order
        index = (7 - i) * stride; // Reverse and apply stride
        vector[index] = (sign & 1) ? cb_gain : -cb_gain;
        pos >>= 3;
        sign >>= 1;
    }
}
