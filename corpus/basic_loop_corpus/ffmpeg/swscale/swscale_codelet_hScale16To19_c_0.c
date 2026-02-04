#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;
extern  uint16_t *src;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    for (j = 0; j < filterSize; j++) {
        val += src[srcPos + j] * filter[filterSize * i + j];
    }
    dst[i] = ((val >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> sh));
}

}
