#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern int shift;
extern int sp1;
extern int sp2;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    shift = !(i & 2);
    sp1 = src[0] << shift;
    sp2 = src[2] << shift;
    t0 = (sp1 + sp2) >> 1;
    t1 = (sp1 - sp2) >> 1;
    dst[0] = t0;
    dst[2] = t1;
    sp1 = src[1] << shift;
    sp2 = src[3] << shift;
    t0 = (sp1 + sp2) >> 1;
    t1 = (sp1 - sp2) >> 1;
    dst[1] = t0;
    dst[3] = t1;
    src += 4;
    dst += 4;
}
}
