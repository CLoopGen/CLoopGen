#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float UINTFLOAT;

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

    INTFLOAT h00_t = h00, h01_t = h01, h02_t = h02, h03_t = h03;
    INTFLOAT h10_t = h10, h11_t = h11, h12_t = h12, h13_t = h13;

    l[n][0] = h00_t * l_re0 + h02_t * r_re0 - h10_t * l_im0 - h12_t * r_im0;
    l[n][1] = h00_t * l_im0 + h02_t * r_im0 + h10_t * l_re0 + h12_t * r_re0;
    r[n][0] = h01_t * l_re0 + h03_t * r_re0 - h11_t * l_im0 - h13_t * r_im0;
    r[n][1] = h01_t * l_im0 + h03_t * r_im0 + h11_t * l_re0 + h13_t * r_re0;

    l[n+1][0] = h00_t * l_re1 + h02_t * r_re1 - h10_t * l_im1 - h12_t * r_im1;
    l[n+1][1] = h00_t * l_im1 + h02_t * r_im1 + h10_t * l_re1 + h12_t * r_re1;
    r[n+1][0] = h01_t * l_re1 + h03_t * r_re1 - h11_t * l_im1 - h13_t * r_im1;
    r[n+1][1] = h01_t * l_im1 + h03_t * r_im1 + h11_t * l_re1 + h13_t * r_re1;
}
}
