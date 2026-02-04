#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_silk_quant_offset[2][2];
extern float *excitationf;
extern int qoffset_high;
extern int voiced;
extern int i;
extern uint32_t seed;
extern int shellblocks;
extern int32_t excitation[320];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < shellblocks << 4; i++) {
    int value = excitation[i];
    excitation[i] = value * 256 | ff_silk_quant_offset[voiced][qoffset_high];
    seed = 196314165 * seed + 907633515;
    int apply_negation = (seed & 2147483648U) ? 1 : 0;
    int adjust = 0;
    if (value < 0) {
        adjust = 20;
    } else if (value > 0) {
        adjust = -20;
    }
    excitation[i] += adjust;
    if (apply_negation) {
        excitation[i] *= -1;
    }
    seed += value;
    excitationf[i] = excitation[i] / 8388608.F;
}
}
