#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t ilinesize;
extern ptrdiff_t tlinesize;
extern ptrdiff_t flinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t olinesize;
extern int w;
extern int h;
extern  uint16_t *in;
extern  uint16_t *threshold;
extern  uint16_t *min;
extern  uint16_t *max;
extern uint16_t *out;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        uint16_t val1 = in[x];
        uint16_t th1 = threshold[x];
        out[x] = val1 < th1 ? min[x] : max[x];

        if (x + 1 < w) {
            uint16_t val2 = in[x + 1];
            uint16_t th2 = threshold[x + 1];
            out[x + 1] = val2 < th2 ? min[x + 1] : max[x + 1];
        }
    }
    in += ilinesize / 2;
    threshold += tlinesize / 2;
    min += flinesize / 2;
    max += slinesize / 2;
    out += olinesize / 2;
}
}
