#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *srcp;
extern  int stride;
extern  int xdia;
extern  int ydia;
extern int16_t *input;
extern int sum;
extern int sumsq;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < ydia; y++) {
    const uint8_t *srcpT = srcp + y * stride * 2;
    x = 0;
    sum += srcpT[x];
    sumsq += srcpT[x] * srcpT[x];
    input[x] = srcpT[x];
    x = 1;
    while (x < xdia) {
        sum += srcpT[x];
        sumsq += srcpT[x] * srcpT[x];
        input[x] = srcpT[x];
        x++;
    }
    input += xdia;
}
}
