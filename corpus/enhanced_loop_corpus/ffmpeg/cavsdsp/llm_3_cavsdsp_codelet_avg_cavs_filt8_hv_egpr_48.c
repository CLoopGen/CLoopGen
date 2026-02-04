#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int stride = 8;
    const int16_t *base_tmp = tmp;
    int t[11];
    for (int j = 0; j < 11; j++) {
        t[j] = base_tmp[(j - 2) * stride];
    }
    uint8_t *d = dst;
    const ptrdiff_t s = dstStride;
    d[0*s] = ((d[0*s]) + cm[( (-t[1] + 5*t[2] + 5*t[3] - t[4] + 64) >> 7 )] + 1) >> 1;
    d[1*s] = ((d[1*s]) + cm[( (-t[2] + 5*t[3] + 5*t[4] - t[5] + 64) >> 7 )] + 1) >> 1;
    d[2*s] = ((d[2*s]) + cm[( (-t[3] + 5*t[4] + 5*t[5] - t[6] + 64) >> 7 )] + 1) >> 1;
    d[3*s] = ((d[3*s]) + cm[( (-t[4] + 5*t[5] + 5*t[6] - t[7] + 64) >> 7 )] + 1) >> 1;
    d[4*s] = ((d[4*s]) + cm[( (-t[5] + 5*t[6] + 5*t[7] - t[8] + 64) >> 7 )] + 1) >> 1;
    d[5*s] = ((d[5*s]) + cm[( (-t[6] + 5*t[7] + 5*t[8] - t[9] + 64) >> 7 )] + 1) >> 1;
    d[6*s] = ((d[6*s]) + cm[( (-t[7] + 5*t[8] + 5*t[9] - t[10] + 64) >> 7 )] + 1) >> 1;
    d[7*s] = ((d[7*s]) + cm[( (-t[8] + 5*t[9] + 5*t[10] + 64) >> 7 )] + 1) >> 1;
    dst++;
    tmp++;
}
}
