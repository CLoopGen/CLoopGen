#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int tmp0;
extern int tmp1;
extern int tmp2;
extern int tmp3;
extern int tmp4;
extern int tmp5;
extern int tmp6;
extern int tmp7;
extern int tmp10;
extern int tmp11;
extern int tmp12;
extern int tmp13;
extern int z5;
extern int z10;
extern int z11;
extern int z12;
extern int z13;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate most intermediate variables to reduce false dependencies and flatten data flow
int local_temp[8]; // Local accumulation to remove global temp[] write per iteration

for (i = 0; i < 8; i++) {
    int b0 = block[8 * 0 + i], b1 = block[8 * 1 + i], b2 = block[8 * 2 + i];
    int b3 = block[8 * 3 + i], b4 = block[8 * 4 + i], b5 = block[8 * 5 + i];
    int b6 = block[8 * 6 + i], b7 = block[8 * 7 + i];

    // Recompute everything locally with minimized intermediates
    int t10 = b0 + b4;
    int t11 = b0 - b4;
    int t13 = b2 + b6;
    int t12 = ((int)((b2 - b6) * 92682U) >> 16) - t13;
    int out0 = t10 + t13;
    int out3 = t10 - t13;
    int out1 = t11 + t12;
    int out2 = t11 - t12;

    int z13 = b5 + b3;
    int z10 = b5 - b3;
    int z11 = b1 + b7;
    int z12 = b1 - b7;
    int t7 = z11 + z13;
    int t11n = ((int)((z11 - z13) * 92682U) >> 16);
    int z5 = ((int)((z10 + z12) * 121095U) >> 16);
    int t10n = ((int)(z12 * 70936U) >> 16) - z5;
    int t12n = ((int)(z10 * (unsigned int)(-171254)) >> 16) + z5;
    int t6 = t12n - t7;
    int t5 = t11n - t6;
    int t4 = t10n + t5;

    // Write directly without using external temp until end (removes intra-loop WAR/WAW on temp)
    local_temp[0] = out0 + t7;
    local_temp[7] = out0 - t7;
    local_temp[1] = out1 + t6;
    local_temp[6] = out1 - t6;
    local_temp[2] = out2 + t5;
    local_temp[5] = out2 - t5;
    local_temp[4] = out3 + t4;
    local_temp[3] = out3 - t4;

    // Finalize store in reverse order to break linear dependency chain
    for (int j = 7; j >= 0; j--) {
        temp[8 * j + i] = local_temp[j];
    }
}
}
