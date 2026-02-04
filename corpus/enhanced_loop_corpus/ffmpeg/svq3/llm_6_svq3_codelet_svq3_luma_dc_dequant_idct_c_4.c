#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *output;
extern  unsigned int qmul;
extern int i;
extern int temp[16];
extern  uint8_t x_offset[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_output[16]; // Introduce local accumulation to modify data dependencies
    for (i = 0; i < 4; i++) {
        const int offset = x_offset[i];
        const int t0 = temp[4 * 0 + i];
        const int t1 = temp[4 * 1 + i];
        const int t2 = temp[4 * 2 + i];
        const int t3 = temp[4 * 3 + i];

        const int z0 = 13 * (t0 + t2);
        const int z1 = 13 * (t0 - t2);
        const int z2 = 7 * t1 - 17 * t3;
        const int z3 = 17 * t1 + 7 * t3;

        // Accumulate into local array to remove direct WAR/WAW on output
        // and introduce temporary storage dependency
        local_output[0] = (int)((z0 + z3) * qmul + 524288) >> 20;
        local_output[2] = (int)((z1 + z2) * qmul + 524288) >> 20;
        local_output[8] = (int)((z1 - z2) * qmul + 524288) >> 20;
        local_output[10] = (int)((z0 - z3) * qmul + 524288) >> 20;

        // Now write back with offset indexing — introduces loop-carried dependence on local_output
        // but removes potential WAW across iterations on shared output
        output[16 * 0 + offset] = local_output[0];
        output[16 * 2 + offset] = local_output[2];
        output[16 * 8 + offset] = local_output[8];
        output[16 * 10 + offset] = local_output[10];
    }
}
