#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v = pix[-1];
    // Change to consecutive array access by unrolling with offset arithmetic using a local pointer
    uint16_t *p = &pix[0];
    int32_t *b = &block[0];
    v += b[0]; p[0] = v;
    v += b[1]; p[1] = v;
    v += b[2]; p[2] = v;
    v += b[3]; p[3] = v;
    v += b[4]; p[4] = v;
    v += b[5]; p[5] = v;
    v += b[6]; p[6] = v;
    v += b[7]; p[7] = v;
    pix += stride;
    block += 8;
}
}
