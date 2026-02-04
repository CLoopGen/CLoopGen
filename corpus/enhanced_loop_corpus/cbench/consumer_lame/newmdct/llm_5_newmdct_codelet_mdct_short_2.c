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
    for (l = 2; l >= 0; l--) {
        out[3 * m + l] = 0.0;
        if (in[6 * l + 5] != 0) {
            out[3 * m + l] += a5 * in[6 * l + 5];
        }
        if (in[6 * l + 4] != 0) {
            out[3 * m + l] += a4 * in[6 * l + 4];
        }
        if (in[6 * l + 3] != 0) {
            out[3 * m + l] += a3 * in[6 * l + 3];
        }
        if (in[6 * l + 2] != 0) {
            out[3 * m + l] += a2 * in[6 * l + 2];
        }
        if (in[6 * l + 1] != 0) {
            out[3 * m + l] += a1 * in[6 * l + 1];
        }
        if (in[6 * l] != 0) {
            out[3 * m + l] += a0 * in[6 * l];
        }
    }
}
}
