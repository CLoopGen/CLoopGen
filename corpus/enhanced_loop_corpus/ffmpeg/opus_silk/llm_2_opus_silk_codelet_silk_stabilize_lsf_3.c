#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    // This changes the access pattern from sequential to strided, assuming order is even for simplicity
    int limit = (order - 1) / 2;
    for (i = 1; i <= limit; i++) {
        int idx1 = 2 * i - 1; // first index in stride
        int idx2 = 2 * i;     // second index in stride (if valid)

        // Process element at idx1
        if (idx1 < order) {
            nlsf[idx1] = (nlsf[idx1] > (nlsf[idx1 - 1] + min_delta[idx1] > 32767 ? 32767 : nlsf[idx1 - 1] + min_delta[idx1])
                          ? nlsf[idx1]
                          : (nlsf[idx1 - 1] + min_delta[idx1] > 32767 ? 32767 : nlsf[idx1 - 1] + min_delta[idx1]));
        }

        // Process element at idx2
        if (idx2 < order) {
            nlsf[idx2] = (nlsf[idx2] > (nlsf[idx2 - 1] + min_delta[idx2] > 32767 ? 32767 : nlsf[idx2 - 1] + min_delta[idx2])
                          ? nlsf[idx2]
                          : (nlsf[idx2 - 1] + min_delta[idx2] > 32767 ? 32767 : nlsf[idx2 - 1] + min_delta[idx2]));
        }
    }
}
