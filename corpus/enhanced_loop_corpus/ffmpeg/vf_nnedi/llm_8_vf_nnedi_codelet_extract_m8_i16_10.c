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
for (y = 0; y < ydia; y += 2) {
    const uint8_t *srcpT1 = srcp + y * stride * 2;
    const uint8_t *srcpT2 = (y + 1 < ydia) ? srcp + (y + 1) * stride * 2 : NULL;
    for (x = 0; x < xdia; x++) {
        sum += srcpT1[x];
        sumsq += srcpT1[x] * srcpT1[x];
        input[x] = srcpT1[x];
        if (srcpT2 != NULL) {
            sum += srcpT2[x];
            sumsq += srcpT2[x] * srcpT2[x];
            input[x + xdia] = srcpT2[x];
        }
    }
    input += (srcpT2 != NULL) ? 2 * xdia : xdia;
}
}
