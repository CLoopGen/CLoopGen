#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    // Introduce WAW and WAR dependencies by reordering writes and using temporary accumulators
    // Also introduce loop-carried dependency via tmp[-tmpStride]
    int16_t acc = (i > 0) ? tmp[-tmpStride] : 0; // Loop-carried dependence: current depends on previous iteration

    tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad + acc;
    tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    tmp[2] = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
    tmp[3] = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;
    tmp[4] = (src[4] + src[5]) * 20 - (src[3] + src[6]) * 5 + (src[2] + src[7]) + pad;
    tmp[5] = (src[5] + src[6]) * 20 - (src[4] + src[7]) * 5 + (src[3] + src[8]) + pad;
    tmp[6] = (src[6] + src[7]) * 20 - (src[5] + src[8]) * 5 + (src[4] + src[9]) + pad;
    
    // Overwrite earlier result with delayed update — introduces WAR hazard if scheduled incorrectly
    tmp[0] = tmp[0] * 2; // Write after write: WAW on tmp[0]

    // Artificially create WAR: use future value now, forcing dependency
    int16_t future = tmp[7];
    tmp[7] = (src[7] + src[8]) * 20 - (src[6] + src[9]) * 5 + (src[5] + src[10]) + pad;
    tmp[0] += future & 0xFFFF; // Use of tmp[7] before it's written in this iteration → WAR-like constraint

    tmp += tmpStride;
    src += srcStride;
}
}
