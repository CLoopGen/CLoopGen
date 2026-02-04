#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *LARpp_j_1;
extern word *LARpp_j;
extern word *LARp;
extern int i;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Introduce artificial loop-carried dependence (RAW) to create data dependency across iterations
    // Use previous iteration's result as input to current iteration, turning independent operations into dependent chain
    word prev_val = 0;  // Carry value from previous iteration, creating RAW dependence
    word *LARpp_j_1_local = LARpp_j_1;
    word *LARpp_j_local = LARpp_j;
    word *LARp_local = LARp;

    for (i = 0; i < 8; i++) {
        // First operation with saturation
        longword ltmp1 = (longword)((LARpp_j_1_local[i]) >> 2) + (longword)((LARpp_j_local[i]) >> 2);
        longword clamped1 = ((ulongword)(ltmp1 - (-32768)) > 65535)
                            ? (ltmp1 > 0 ? 32767 : -32768)
                            : ltmp1;

        // Second operation now depends on both current input AND previous output (introducing RAW)
        longword ltmp2 = (longword)clamped1 + (longword)((LARpp_j_local[i]) >> 1) + (longword)prev_val;
        longword clamped2 = ((ulongword)(ltmp2 - (-32768)) > 65535)
                            ? (ltmp2 > 0 ? 32767 : -32768)
                            : ltmp2;

        LARp_local[i] = (word)clamped2;
        prev_val = LARp_local[i];  // Create loop-carried dependence: current output used in next iteration
    }
}
