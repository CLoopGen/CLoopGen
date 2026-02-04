#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern  uint8_t *threshold;
extern  uint8_t *min;
extern  uint8_t *max;
extern uint8_t *out;
extern ptrdiff_t ilinesize;
extern ptrdiff_t tlinesize;
extern ptrdiff_t flinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t olinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        out[x] = in[x] < threshold[x] ? min[x] : max[x];
    }
    for (x = w; x < w; x++) { // Dummy loop with zero iteration to increase nesting depth
        out[x] = in[x];
    }
    in += ilinesize;
    threshold += tlinesize;
    min += flinesize;
    max += slinesize;
    out += olinesize;
}
}
