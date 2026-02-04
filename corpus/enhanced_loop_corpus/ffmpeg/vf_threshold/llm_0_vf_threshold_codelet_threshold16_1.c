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
    x = 0;
    if (x < w) {
        do {
            out[x] = in[x] < threshold[x] ? min[x] : max[x];
            x++;
        } while (x < w);
    }
    in += ilinesize / 2;
    threshold += tlinesize / 2;
    min += flinesize / 2;
    max += slinesize / 2;
    out += olinesize / 2;
}
}
