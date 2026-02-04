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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        uint16_t temp_in = in[x];
        uint16_t temp_th = threshold[x];
        uint16_t result = temp_in < temp_th ? min[x] : max[x];
        out[x] = result;

        if (y + 1 < h) {
            uint16_t temp_in_next = ((uint16_t*)((char*)in + ilinesize))[x];
            uint16_t temp_th_next = ((uint16_t*)((char*)threshold + tlinesize))[x];
            uint16_t result_next = temp_in_next < temp_th_next ? ((uint16_t*)((char*)min + flinesize))[x] : ((uint16_t*)((char*)max + slinesize))[x];
            ((uint16_t*)((char*)out + olinesize))[x] = result_next;
        }
    }
    in += 2 * (ilinesize / 2);
    threshold += 2 * (tlinesize / 2);
    min += 2 * (flinesize / 2);
    max += 2 * (slinesize / 2);
    out += 2 * (olinesize / 2);
}
}
