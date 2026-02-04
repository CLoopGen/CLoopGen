#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t linesize1;
ptrdiff_t dlinesize;
int w0;
int h0;
unsigned int *cchange;
uint16_t *i;
uint16_t *d;
int x;
int y;

void init_vars() {
    w0 = 1024;
    h0 = 512;
    linesize1 = w0 * sizeof(uint16_t);
    dlinesize = w0 * sizeof(uint16_t);

    cchange = (unsigned int *)aligned_alloc(32, 65536 * sizeof(unsigned int));
    i = (uint16_t *)aligned_alloc(32, h0 * linesize1);
    d = (uint16_t *)aligned_alloc(32, h0 * dlinesize);

    for (int idx = 0; idx < 65536; idx++) {
        cchange[idx] = (unsigned int)(idx * 0.75f + 1.0f);
    }

    for (int idx = 0; idx < h0 * w0; idx++) {
        i[idx] = rand() & 0xFFFF;
        d[idx] = 0;
    }
}