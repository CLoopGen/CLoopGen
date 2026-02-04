#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize1;
extern ptrdiff_t dlinesize;
extern int w0;
extern int h0;
extern unsigned int *cchange;
extern  uint16_t *i;
extern uint16_t *d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h0; y++) {
        for (x = 0; x < w0; x += 2) {
            d[x] = cchange[i[x]] + 1;
            if (x + 1 < w0) {
                d[x + 1] = cchange[i[x + 1]] + 1;
            }
        }
        d += dlinesize / 2;
        i += linesize1 / 2;
    }
}
