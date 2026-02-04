#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 cos_s[6][6];
extern FLOAT8 *out;
extern FLOAT8 *in;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 12 / 2 - 1; m >= 0; m -= 2) {
    int l;
    FLOAT8 a0_0, a1_0, a2_0, a3_0, a4_0, a5_0;
    FLOAT8 a0_1, a1_1, a2_1, a3_1, a4_1, a5_1;
    a0_0 = cos_s[m][0]; a1_0 = cos_s[m][1]; a2_0 = cos_s[m][2];
    a3_0 = cos_s[m][3]; a4_0 = cos_s[m][4]; a5_0 = cos_s[m][5];
    if (m > 0) {
        a0_1 = cos_s[m-1][0]; a1_1 = cos_s[m-1][1]; a2_1 = cos_s[m-1][2];
        a3_1 = cos_s[m-1][3]; a4_1 = cos_s[m-1][4]; a5_1 = cos_s[m-1][5];
    }
    for (l = 2; l >= 0; l--) {
        out[3 * m + l] = a0_0 * in[6 * l] + a1_0 * in[6 * l + 1] + a2_0 * in[6 * l + 2] +
                         a3_0 * in[6 * l + 3] + a4_0 * in[6 * l + 4] + a5_0 * in[6 * l + 5];
        if (m > 0) {
            out[3 * (m - 1) + l] = a0_1 * in[6 * l] + a1_1 * in[6 * l + 1] + a2_1 * in[6 * l + 2] +
                                   a3_1 * in[6 * l + 3] + a4_1 * in[6 * l + 4] + a5_1 * in[6 * l + 5];
        }
    }
}
}
