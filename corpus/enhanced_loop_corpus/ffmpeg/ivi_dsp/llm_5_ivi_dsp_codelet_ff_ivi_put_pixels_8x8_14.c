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
        for (x = 0; x < 8; x++) {
            if (x >= y) {  // Upper triangular pattern: copy only when x >= y
                out[x] = in[x];
            } else {
                out[x] = -in[x];  // Mirror with sign flip for x < y
            }
        }
    }
}
