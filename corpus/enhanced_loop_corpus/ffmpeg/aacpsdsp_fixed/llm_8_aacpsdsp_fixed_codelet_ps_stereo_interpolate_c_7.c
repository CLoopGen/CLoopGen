#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef unsigned int UINTFLOAT;

extern INTFLOAT (*l)[2];
extern INTFLOAT (*r)[2];
extern int len;
extern INTFLOAT h0;
extern INTFLOAT h1;
extern INTFLOAT h2;
extern INTFLOAT h3;
extern UINTFLOAT hs0;
extern UINTFLOAT hs1;
extern UINTFLOAT hs2;
extern UINTFLOAT hs3;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < len; n += 2) {
    INTFLOAT l_re1 = l[n][0];
    INTFLOAT l_im1 = l[n][1];
    INTFLOAT r_re1 = r[n][0];
    INTFLOAT r_im1 = r[n][1];
    INTFLOAT l_re2 = (n+1 < len) ? l[n+1][0] : l_re1;
    INTFLOAT l_im2 = (n+1 < len) ? l[n+1][1] : l_im1;
    INTFLOAT r_re2 = (n+1 < len) ? r[n+1][0] : r_re1;
    INTFLOAT r_im2 = (n+1 < len) ? r[n+1][1] : r_im1;

    h0 += hs0; h1 += hs1; h2 += hs2; h3 += hs3;
    INTFLOAT h0_val = h0, h1_val = h1, h2_val = h2, h3_val = h3;

    h0 += hs0; h1 += hs1; h2 += hs2; h3 += hs3;

    l[n][0] = (int)((((int64_t)(h0_val) * (l_re1)) + ((int64_t)(h2_val) * (r_re1)) + 536870912) >> 30);
    l[n][1] = (int)((((int64_t)(h0_val) * (l_im1)) + ((int64_t)(h2_val) * (r_im1)) + 536870912) >> 30);
    r[n][0] = (int)((((int64_t)(h1_val) * (l_re1)) + ((int64_t)(h3_val) * (r_re1)) + 536870912) >> 30);
    r[n][1] = (int)((((int64_t)(h1_val) * (l_im1)) + ((int64_t)(h3_val) * (r_im1)) + 536870912) >> 30);

    if (n+1 < len) {
        l[n+1][0] = (int)((((int64_t)(h0) * (l_re2)) + ((int64_t)(h2) * (r_re2)) + 536870912) >> 30);
        l[n+1][1] = (int)((((int64_t)(h0) * (l_im2)) + ((int64_t)(h2) * (r_im2)) + 536870912) >> 30);
        r[n+1][0] = (int)((((int64_t)(h1) * (l_re2)) + ((int64_t)(h3) * (r_re2)) + 536870912) >> 30);
        r[n+1][1] = (int)((((int64_t)(h1) * (l_im2)) + ((int64_t)(h3) * (r_im2)) + 536870912) >> 30);
    }
}
}
