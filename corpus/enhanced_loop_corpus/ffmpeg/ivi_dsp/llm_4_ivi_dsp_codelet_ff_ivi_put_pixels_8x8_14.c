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
    for (y = 0; y < 8; out += pitch, in += 8, y++) {
        if (!(y & 1)) {  // Only process even rows
            for (x = 0; x < 8; x++) {
                out[x] = in[x];
            }
        } else {
            for (x = 0; x < 8; x++) {
                out[x] = 0;  // Fill odd rows with zero
            }
        }
    }
}
