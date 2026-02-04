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
        int32_t acc = 0;
        for (x = 0; x < 8; x++) {
            acc += in[x];  // Introduce loop-carried dependency (WAW on 'acc')
            out[x] = (int16_t)(in[x] + acc);  // Create RAW: 'out[x]' depends on updated 'acc' and current 'in[x]'
        }
    }
}
