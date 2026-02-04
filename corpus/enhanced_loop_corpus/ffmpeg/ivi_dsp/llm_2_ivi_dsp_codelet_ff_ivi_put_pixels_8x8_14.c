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
    // Variant 1: Strided memory access with reversed row traversal
    for (y = 7; y >= 0; y--, out += pitch, in -= 8)
        for (x = 0; x < 8; x++)
            out[7 - x] = in[x];
}
