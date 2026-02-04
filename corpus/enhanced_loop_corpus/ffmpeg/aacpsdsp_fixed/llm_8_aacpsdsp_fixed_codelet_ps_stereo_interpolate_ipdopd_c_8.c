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
for (n = 0; n < len; n += 2) {
    if (n + 1 >= len) break;
    INTFLOAT l_re0 = l[n][0];
    INTFLOAT l_im0 = l[n][1];
    INTFLOAT r_re0 = r[n][0];
    INTFLOAT r_im0 = r[n][1];
    INTFLOAT l_re1 = l[n+1][0];
    INTFLOAT l_im1 = l[n+1][1];
    INTFLOAT r_re1 = r[n+1][0];
    INTFLOAT r_im1 = r[n+1][1];

    h00 += hs00; h01 += hs01; h02 += hs02; h03 += hs03;
    h10 += hs10; h11 += hs11; h12 += hs12; h13 += hs13;

    INTFLOAT temp_l0_re = (int)((((int64_t)(h00) * (l_re0)) + ((int64_t)(h02) * (r_re0)) - ((int64_t)(h10) * (l_im0)) - ((int64_t)(h12) * (r_im0)) + 536870912) >> 30);
    INTFLOAT temp_l0_im = (int)((((int64_t)(h00) * (l_im0)) + ((int64_t)(h02) * (r_im0)) + ((int64_t)(h10) * (l_re0)) + ((int64_t)(h12) * (r_re0)) + 536870912) >> 30);
    INTFLOAT temp_r0_re = (int)((((int64_t)(h01) * (l_re0)) + ((int64_t)(h03) * (r_re0)) - ((int64_t)(h11) * (l_im0)) - ((int64_t)(h13) * (r_im0)) + 536870912) >> 30);
    INTFLOAT temp_r0_im = (int)((((int64_t)(h01) * (l_im0)) + ((int64_t)(h03) * (r_im0)) + ((int64_t)(h11) * (l_re0)) + ((int64_t)(h13) * (r_re0)) + 536870912) >> 30);

    INTFLOAT temp_l1_re = (int)((((int64_t)(h00) * (l_re1)) + ((int64_t)(h02) * (r_re1)) - ((int64_t)(h10) * (l_im1)) - ((int64_t)(h12) * (r_im1)) + 536870912) >> 30);
    INTFLOAT temp_l1_im = (int)((((int64_t)(h00) * (l_im1)) + ((int64_t)(h02) * (r_im1)) + ((int64_t)(h10) * (l_re1)) + ((int64_t)(h12) * (r_re1)) + 536870912) >> 30);
    INTFLOAT temp_r1_re = (int)((((int64_t)(h01) * (l_re1)) + ((int64_t)(h03) * (r_re1)) - ((int64_t)(h11) * (l_im1)) - ((int64_t)(h13) * (r_im1)) + 536870912) >> 30);
    INTFLOAT temp_r1_im = (int)((((int64_t)(h01) * (l_im1)) + ((int64_t)(h03) * (r_im1)) + ((int64_t)(h11) * (l_re1)) + ((int64_t)(h13) * (r_re1)) + 536870912) >> 30);

    l[n][0] = temp_l0_re;
    l[n][1] = temp_l0_im;
    r[n][0] = temp_r0_re;
    r[n][1] = temp_r0_im;

    l[n+1][0] = temp_l1_re;
    l[n+1][1] = temp_l1_im;
    r[n+1][0] = temp_r1_re;
    r[n+1][1] = temp_r1_im;
}
}
