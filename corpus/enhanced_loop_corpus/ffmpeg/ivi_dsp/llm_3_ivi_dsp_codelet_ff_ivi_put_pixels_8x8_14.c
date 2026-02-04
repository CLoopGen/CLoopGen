#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int16_t *out;
extern ptrdiff_t pitch;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive linear indexing using pointer arithmetic without nested indexing
    int32_t *in_ptr = in;
    int16_t *out_row = out;
    for (y = 0; y < 8; y++) {
        int16_t *out_ptr = out_row;
        for (x = 0; x < 8; x++) {
            *out_ptr++ = (int16_t)*in_ptr++;
        }
        out_row += pitch;
    }
}
