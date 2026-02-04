#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed filter application (indirect-like pattern using index offsets)
    // Access src with increasing strides simulated via offset indexing, creating non-consecutive access
    const int offsets[4] = { -1, 0, 1, 2 }; // original access pattern as explicit offset vector
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            int16_t sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += filter[k] * src[x + offsets[k]];
            }
            tmp[x] = sum >> 2;
        }
        src += srcstride;
        tmp += 64;
    }
}
