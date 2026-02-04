#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl++) {
    // Eliminate loop-carried dependencies by reordering and using temporary storage
    real_t temp[256];
    for (int i = 0; i < 256; i++) {
        temp[i] = (real_t)1.; // Prepare diagonal values without writing to aa yet
        for (int j = 0; j < 256; j++) {
            aa[j][i] = (real_t)0.; // Column-wise zeroing remains
        }
    }
    // Now write diagonals in a separate independent loop (eliminates WAW or WAR if multiple writes were possible)
    for (int i = 0; i < 256; i++) {
        aa[i][i] = temp[i];
    }
}
}
