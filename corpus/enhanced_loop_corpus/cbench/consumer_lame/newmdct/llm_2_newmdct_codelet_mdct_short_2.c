#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 cos_s[6][6];
extern FLOAT8 *out;
extern FLOAT8 *in;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 12 / 2 - 1; m >= 0; --m) {
    int l;
    FLOAT8 a0, a1, a2, a3, a4, a5;
    a0 = cos_s[m][0];
    a1 = cos_s[m][1];
    a2 = cos_s[m][2];
    a3 = cos_s[m][3];
    a4 = cos_s[m][4];
    a5 = cos_s[m][5];
    for (l = 0; l < 3; ++l) {
        int idx = 3 * m + l;
        int base_in = 6 * l;
        out[idx] = a0 * in[base_in] + a1 * in[base_in + 1] + a2 * in[base_in + 2] +
                   a3 * in[base_in + 3] + a4 * in[base_in + 4] + a5 * in[base_in + 5];
    }
}
}
