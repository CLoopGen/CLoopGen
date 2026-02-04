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
    int l, k;
    FLOAT8 a[6];
    for (k = 0; k < 6; ++k) {
        a[k] = cos_s[m][k];
    }
    for (l = 2; l >= 0; l--) {
        out[3 * m + l] = a[0] * in[6 * l] + a[1] * in[6 * l + 1] + a[2] * in[6 * l + 2] + 
                         a[3] * in[6 * l + 3] + a[4] * in[6 * l + 4] + a[5] * in[6 * l + 5];
    }
}
}
