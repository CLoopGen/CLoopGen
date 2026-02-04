#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce data reuse and break some RAW dependencies by re-reading values multiple times
    // Eliminate local variables to increase memory dependency on src[]
    // This increases memory-level parallelism pressure and removes register-held temporaries

    #define LOAD(k) src[(k) * srcStride]

    // Directly embed loads into expressions — increases RAW hazards from repeated src[] access
    dst[0 * dstStride] = cm[(((LOAD(0) + LOAD(1)) * 20 - (LOAD(0) + LOAD(2)) * 6 + (LOAD(1) + LOAD(3)) * 3 - (LOAD(2) + LOAD(4))) + 15) >> 5];
    dst[1 * dstStride] = cm[(((LOAD(1) + LOAD(2)) * 20 - (LOAD(0) + LOAD(3)) * 6 + (LOAD(0) + LOAD(4)) * 3 - (LOAD(1) + LOAD(5))) + 15) >> 5];
    dst[2 * dstStride] = cm[(((LOAD(2) + LOAD(3)) * 20 - (LOAD(1) + LOAD(4)) * 6 + (LOAD(0) + LOAD(5)) * 3 - (LOAD(0) + LOAD(6))) + 15) >> 5];
    dst[3 * dstStride] = cm[(((LOAD(3) + LOAD(4)) * 20 - (LOAD(2) + LOAD(5)) * 6 + (LOAD(1) + LOAD(6)) * 3 - (LOAD(0) + LOAD(7))) + 15) >> 5];
    dst[4 * dstStride] = cm[(((LOAD(4) + LOAD(5)) * 20 - (LOAD(3) + LOAD(6)) * 6 + (LOAD(2) + LOAD(7)) * 3 - (LOAD(1) + LOAD(8))) + 15) >> 5];
    dst[5 * dstStride] = cm[(((LOAD(5) + LOAD(6)) * 20 - (LOAD(4) + LOAD(7)) * 6 + (LOAD(3) + LOAD(8)) * 3 - (LOAD(2) + LOAD(9))) + 15) >> 5];
    dst[6 * dstStride] = cm[(((LOAD(6) + LOAD(7)) * 20 - (LOAD(5) + LOAD(8)) * 6 + (LOAD(4) + LOAD(9)) * 3 - (LOAD(3) + LOAD(10))) + 15) >> 5];
    dst[7 * dstStride] = cm[(((LOAD(7) + LOAD(8)) * 20 - (LOAD(6) + LOAD(9)) * 6 + (LOAD(5) + LOAD(10)) * 3 - (LOAD(4) + LOAD(11))) + 15) >> 5];
    dst[8 * dstStride] = cm[(((LOAD(8) + LOAD(9)) * 20 - (LOAD(7) + LOAD(10)) * 6 + (LOAD(6) + LOAD(11)) * 3 - (LOAD(5) + LOAD(12))) + 15) >> 5];
    dst[9 * dstStride] = cm[(((LOAD(9) + LOAD(10)) * 20 - (LOAD(8) + LOAD(11)) * 6 + (LOAD(7) + LOAD(12)) * 3 - (LOAD(6) + LOAD(13))) + 15) >> 5];
    dst[10 * dstStride] = cm[(((LOAD(10) + LOAD(11)) * 20 - (LOAD(9) + LOAD(12)) * 6 + (LOAD(8) + LOAD(13)) * 3 - (LOAD(7) + LOAD(14))) + 15) >> 5];
    dst[11 * dstStride] = cm[(((LOAD(11) + LOAD(12)) * 20 - (LOAD(10) + LOAD(13)) * 6 + (LOAD(9) + LOAD(14)) * 3 - (LOAD(8) + LOAD(15))) + 15) >> 5];
    dst[12 * dstStride] = cm[(((LOAD(12) + LOAD(13)) * 20 - (LOAD(11) + LOAD(14)) * 6 + (LOAD(10) + LOAD(15)) * 3 - (LOAD(9) + LOAD(16))) + 15) >> 5];
    dst[13 * dstStride] = cm[(((LOAD(13) + LOAD(14)) * 20 - (LOAD(12) + LOAD(15)) * 6 + (LOAD(11) + LOAD(16)) * 3 - (LOAD(10) + LOAD(16))) + 15) >> 5];
    dst[14 * dstStride] = cm[(((LOAD(14) + LOAD(15)) * 20 - (LOAD(13) + LOAD(16)) * 6 + (LOAD(12) + LOAD(16)) * 3 - (LOAD(11) + LOAD(15))) + 15) >> 5];
    dst[15 * dstStride] = cm[(((LOAD(15) + LOAD(16)) * 20 - (LOAD(14) + LOAD(16)) * 6 + (LOAD(13) + LOAD(15)) * 3 - (LOAD(12) + LOAD(14))) + 15) >> 5];

    #undef LOAD

    // Introduce artificial loop-carried dependency via scalar propagation
    static uint8_t prev = 0; // Creates loop-carried state
    dst[0 * dstStride] ^= prev; // Modify first output using previous iteration's value
    prev = dst[15 * dstStride]; // Feed last output into next iteration

    dst++;
    src++;
}
}
