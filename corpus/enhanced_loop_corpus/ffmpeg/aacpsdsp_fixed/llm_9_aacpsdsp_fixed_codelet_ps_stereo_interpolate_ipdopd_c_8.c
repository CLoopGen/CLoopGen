#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef unsigned int UINTFLOAT;

extern INTFLOAT (*l)[2];
extern INTFLOAT (*r)[2];
extern int len;
extern INTFLOAT h00;
extern INTFLOAT h10;
extern INTFLOAT h01;
extern INTFLOAT h11;
extern INTFLOAT h02;
extern INTFLOAT h12;
extern INTFLOAT h03;
extern INTFLOAT h13;
extern UINTFLOAT hs00;
extern UINTFLOAT hs10;
extern UINTFLOAT hs01;
extern UINTFLOAT hs11;
extern UINTFLOAT hs02;
extern UINTFLOAT hs12;
extern UINTFLOAT hs03;
extern UINTFLOAT hs13;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < len && n < 64; n++) {
    INTFLOAT l_re = l[n][0];
    INTFLOAT l_im = l[n][1];
    INTFLOAT r_re = r[n][0];
    INTFLOAT r_im = r[n][1];

    h00 += hs00 << 1;
    h01 += hs01 << 1;
    h02 += hs02 << 1;
    h03 += hs03 << 1;
    h10 += hs10 << 1;
    h11 += hs11 << 1;
    h12 += hs12 << 1;
    h13 += hs13 << 1;

    INTFLOAT scaled_h00 = h00 >> 1;
    INTFLOAT scaled_h02 = h02 >> 1;
    INTFLOAT scaled_h10 = h10 >> 1;
    INTFLOAT scaled_h12 = h12 >> 1;
    INTFLOAT scaled_h01 = h01 >> 1;
    INTFLOAT scaled_h03 = h03 >> 1;
    INTFLOAT scaled_h11 = h11 >> 1;
    INTFLOAT scaled_h13 = h13 >> 1;

    l[n][0] = (int)((((int64_t)(scaled_h00) * (l_re)) + ((int64_t)(scaled_h02) * (r_re)) - ((int64_t)(scaled_h10) * (l_im)) - ((int64_t)(scaled_h12) * (r_im)) + 268435456) >> 29);
    l[n][1] = (int)((((int64_t)(scaled_h00) * (l_im)) + ((int64_t)(scaled_h02) * (r_im)) + ((int64_t)(scaled_h10) * (l_re)) + ((int64_t)(scaled_h12) * (r_re)) + 268435456) >> 29);
    r[n][0] = (int)((((int64_t)(scaled_h01) * (l_re)) + ((int64_t)(scaled_h03) * (r_re)) - ((int64_t)(scaled_h11) * (l_im)) - ((int64_t)(scaled_h13) * (r_im)) + 268435456) >> 29);
    r[n][1] = (int)((((int64_t)(scaled_h01) * (l_im)) + ((int64_t)(scaled_h03) * (r_im)) + ((int64_t)(scaled_h11) * (l_re)) + ((int64_t)(scaled_h13) * (r_re)) + 268435456) >> 29);
}
}
