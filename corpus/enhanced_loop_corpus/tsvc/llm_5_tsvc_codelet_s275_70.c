#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 0; i < 256; i++) {
        // Introduce additional control flow: split processing based on index parity
        // This creates two distinct execution paths within the same loop
        if (aa[0][i] > (real_t)0.) {
            if (i % 2 == 0) {
                // Even indices: perform standard recurrence
                for (int j = 1; j < 256; j++) {
                    aa[j][i] = aa[j - 1][i] + bb[j][i] * cc[j][i];
                }
            } else {
                // Odd indices: scale the operation by a factor of 2
                for (int j = 1; j < 256; j++) {
                    real_t temp = bb[j][i] * cc[j][i] * (real_t)2.0;
                    aa[j][i] = aa[j - 1][i] + temp;
                }
            }
        }
    }
}
}
