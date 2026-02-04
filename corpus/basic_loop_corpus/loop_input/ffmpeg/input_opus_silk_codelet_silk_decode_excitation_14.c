#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint8_t ff_silk_quant_offset[2][2] = {{0, 1}, {2, 3}};
float *excitationf;
int qoffset_high = 1;
int voiced = 0;
int i;
uint32_t seed = 123456789;
int shellblocks;
int32_t excitation[320];

void init_vars() {
    shellblocks = 80; // ensures loop runs for shellblocks << 4 = 1280 iterations, but we limit to excitation size (320)
                      // so we must adjust shellblocks to not exceed bounds: i < shellblocks << 4 --> i < 320
                      // => shellblocks << 4 < 320 => shellblocks < 20
    shellblocks = 19; // allows i up to (19<<4)-1 = 303, within [0,319]

    // Allocate and initialize excitationf array
    excitationf = (float*)calloc(320, sizeof(float));
    if (!excitationf) {
        exit(1);
    }

    // Initialize excitation array with non-zero values for meaningful computation
    for (int idx = 0; idx < 320; idx++) {
        excitation[idx] = (rand() % 4000) - 2000; // random values in [-2000, 1999]
    }

    // Reinitialize seed for deterministic behavior
    seed = 123456789;
}