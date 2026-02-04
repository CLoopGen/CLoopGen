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
    FLOAT8 a[6];
    for (int k = 0; k < 6; ++k) {
        a[k] = cos_s[m][k];
    }
    for (l = 2; l >= 0; l--) {
        FLOAT8 sum = 0.0;
        for (int n = 0; n < 6; ++n) {
            sum += a[n] * in[6 * l + n];
        }
        out[3 * m + l] = sum;
    }
}
}
