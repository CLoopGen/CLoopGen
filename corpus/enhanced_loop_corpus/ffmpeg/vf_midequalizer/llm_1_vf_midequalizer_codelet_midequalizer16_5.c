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
    d[y * (dlinesize / 2)] = cchange[i[y * (linesize1 / 2)]];
    for (x = 1; x < w0; x++) {
        d[y * (dlinesize / 2) + x] = cchange[i[y * (linesize1 / 2) + x]];
    }
}
}
