#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int t5;
extern int t6;
extern int t7;
extern int t8;
extern int16_t *src;
extern int16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    // Eliminate some loop-carried dependencies by combining expressions
    // and introducing local reuse to create WAW-like patterns in register usage

    int base_t1 = 12 * (src[0] + src[32]) + 4;
    int base_t2 = 12 * (src[0] - src[32]) + 4;
    int base_t3 = 16 * src[16] + 6 * src[48];
    int base_t4 = 6 * src[16] - 16 * src[48];

    // Merge intermediate results earlier to increase expression complexity but reduce live ranges
    int combined1 = base_t1 + base_t3;  // t5
    int combined2 = base_t2 + base_t4;  // t6
    int combined3 = base_t2 - base_t4;  // t7
    int combined4 = base_t1 - base_t3;  // t8

    // Create artificial write-after-write on t1-t4 by reusing variable names after full definition
    t1 = 16 * src[8] + 15 * src[24] + 9 * src[40] + 4 * src[56];
    t2 = 15 * src[8] - 4 * src[24] - 16 * src[40] - 9 * src[56];
    t3 = 9 * src[8] - 16 * src[24] + 4 * src[40] + 15 * src[56];
    t4 = 4 * src[8] - 9 * src[24] + 15 * src[40] - 16 * src[56];

    // Change memory store order to alter potential vectorization assumptions
    dst[0] = (combined1 + t1) >> 3;
    dst[7] = (combined1 - t1) >> 3;
    dst[1] = (combined2 + t2) >> 3;
    dst[6] = (combined2 - t2) >> 3;
    dst[2] = (combined3 + t3) >> 3;
    dst[5] = (combined3 - t3) >> 3;
    dst[3] = (combined4 + t4) >> 3;
    dst[4] = (combined4 - t4) >> 3;

    // Add a fake dependency on previous iteration via conditional that is always true but breaks independence
    if (i > 0) {
        // Artificially introduce a loop-carried RAW dependency
        dst[0] += (dst[-8] & 0); // No actual effect, but creates apparent dependency
    }

    src += 1;
    dst += 8;
}
}
