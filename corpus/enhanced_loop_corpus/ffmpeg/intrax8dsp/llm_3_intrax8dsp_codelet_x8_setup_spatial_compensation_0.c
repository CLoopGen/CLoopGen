#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory write using indirect indexing with fixed offsets array to simulate irregular but predictable access
    static const int offsets[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access pattern
    for (i = 0; i < 8; i++) {
        int idx = offsets[i];
        c = *(ptr - 1);
        dst[0 + idx] = c;
        c = *ptr;
        sum += c;
        min_pix = (min_pix > c) ? c : min_pix;
        max_pix = (max_pix > c) ? max_pix : c;
        dst[8 + idx] = c;
        ptr += stride;
    }
}
