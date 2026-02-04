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
    const FLOAT8* cos_row = cos_s[m];
    for (l = 2; l >= 0; l--) {
        const FLOAT8* in_ptr = &in[6 * l];
        FLOAT8 sum = cos_row[0] * in_ptr[0] +
                     cos_row[1] * in_ptr[1] +
                     cos_row[2] * in_ptr[2] +
                     cos_row[3] * in_ptr[3] +
                     cos_row[4] * in_ptr[4] +
                     cos_row[5] * in_ptr[5];
        out[3 * m + l] = sum;
    }
}
}
