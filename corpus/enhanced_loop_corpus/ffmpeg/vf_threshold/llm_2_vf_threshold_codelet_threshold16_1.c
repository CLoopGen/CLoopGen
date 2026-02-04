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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    // This variant processes two elements per iteration to promote consecutive, coalesced memory access
    for (y = 0; y < h; y++) {
        uint16_t *in_row = in;
        uint16_t *th_row = threshold;
        uint16_t *min_row = min;
        uint16_t *max_row = max;
        uint16_t *out_row = out;
        int x;
        for (x = 0; x <= w - 2; x += 2) {
            out_row[x]     = in_row[x]     < th_row[x]     ? min_row[x]     : max_row[x];
            out_row[x + 1] = in_row[x + 1] < th_row[x + 1] ? min_row[x + 1] : max_row[x + 1];
        }
        // Handle remaining element if width is odd
        if (x < w) {
            out_row[x] = in_row[x] < th_row[x] ? min_row[x] : max_row[x];
        }
        in += ilinesize / 2;
        threshold += tlinesize / 2;
        min += flinesize / 2;
        max += slinesize / 2;
        out += olinesize / 2;
    }
}
