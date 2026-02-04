#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Block Access using pointer arithmetic with local pointers
    // Restructure to use base pointers incremented per row, and process column in forward order
    // Simulates prefetching-friendly access by treating rows as contiguous blocks
    uint8_t *drow = dst;
    uint8_t *mrow = msrc;
    uint8_t *arow = asrc;

    for (y = 0; y < h; y++) {
        uint8_t *dp = drow;
        uint8_t *mp = mrow;
        uint8_t *ap = arow;

        for (x = 0; x < w; x++) {
            if (*(ap + x) > 0 && *(ap + x) < 255)
                *(dp + x) = ((*(mp + x) * 255 / *(ap + x)) > 255 ? 255 : (*(mp + x) * 255 / *(ap + x)));
            else
                *(dp + x) = *(mp + x);
        }

        drow += dlinesize;
        mrow += mlinesize;
        arow += alinesize;
    }
}
