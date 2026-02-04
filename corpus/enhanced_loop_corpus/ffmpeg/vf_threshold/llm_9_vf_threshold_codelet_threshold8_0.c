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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        out[x] = in[x] < threshold[x] ? min[x] : max[x];
        if (y + 1 < h) {
            int offset = x + olinesize;
            out[offset] = in[ilinesize + x] < threshold[tlinesize + x] ? 
                          min[flinesize + x] : max[slinesize + x];
        }
    }
    in += 2 * ilinesize;
    threshold += 2 * tlinesize;
    min += 2 * flinesize;
    max += 2 * slinesize;
    out += 2 * olinesize;
}
}
