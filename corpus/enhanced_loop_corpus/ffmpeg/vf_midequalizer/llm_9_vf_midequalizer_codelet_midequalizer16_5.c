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
    for (y = 0; y < h0; y += 2) {
        for (x = 0; x < w0; x++) {
            uint32_t val = i[x];
            d[x] = cchange[val] ^ cchange[val ^ 0xFF];
        }
        d += dlinesize / 2;
        i += linesize1 / 2;
        if (y + 1 < h0) {
            for (x = 0; x < w0; x++) {
                d[x] = cchange[i[x]] ^ 0xFFFF;
            }
            d += dlinesize / 2;
            i += linesize1 / 2;
        }
    }
}
