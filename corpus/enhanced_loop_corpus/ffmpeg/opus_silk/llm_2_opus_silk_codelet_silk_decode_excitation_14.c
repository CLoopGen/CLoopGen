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
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < shellblocks << 4; i += 2) {
        int value1 = excitation[i];
        excitation[i] = value1 * 256 | ff_silk_quant_offset[voiced][qoffset_high];
        if (value1 < 0)
            excitation[i] += 20;
        else if (value1 > 0)
            excitation[i] -= 20;
        seed = 196314165 * seed + 907633515;
        if (seed & 2147483648U)
            excitation[i] *= -1;
        seed += value1;
        excitationf[i] = excitation[i] / 8388608.F;

        if (i + 1 < (shellblocks << 4)) {
            int value2 = excitation[i + 1];
            excitation[i + 1] = value2 * 256 | ff_silk_quant_offset[voiced][qoffset_high];
            if (value2 < 0)
                excitation[i + 1] += 20;
            else if (value2 > 0)
                excitation[i + 1] -= 20;
            seed = 196314165 * seed + 907633515;
            if (seed & 2147483648U)
                excitation[i + 1] *= -1;
            seed += value2;
            excitationf[i + 1] = excitation[i + 1] / 8388608.F;
        }
    }
}
