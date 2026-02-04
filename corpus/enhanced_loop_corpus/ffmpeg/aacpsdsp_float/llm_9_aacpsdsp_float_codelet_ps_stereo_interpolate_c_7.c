#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float UINTFLOAT;

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
    int stride = 4;
    for (n = 0; n < len; n++) {
        INTFLOAT l_re = l[n][0];
        INTFLOAT l_im = l[n][1];
        INTFLOAT r_re = r[n][0];
        INTFLOAT r_im = r[n][1];

        h0 += hs0 * stride;
        h1 += hs1 * stride;
        h2 += hs2 * stride;
        h3 += hs3 * stride;

        INTFLOAT temp_l_re = (h0) * l_re + (h2) * r_re;
        INTFLOAT temp_l_im = (h0) * l_im + (h2) * r_im;
        INTFLOAT temp_r_re = (h1) * l_re + (h3) * r_re;
        INTFLOAT temp_r_im = (h1) * l_im + (h3) * r_im;

        l[n][0] = temp_l_re;
        l[n][1] = temp_l_im;
        r[n][0] = temp_r_re;
        r[n][1] = temp_r_im;

        for (int unroll = 0; unroll < 3 && n + 1 < len; ++unroll) {
            n++;
            l_re = l[n][0]; l_im = l[n][1];
            r_re = r[n][0]; r_im = r[n][1];

            l[n][0] = (h0) * l_re + (h2) * r_re;
            l[n][1] = (h0) * l_im + (h2) * r_im;
            r[n][0] = (h1) * l_re + (h3) * r_re;
            r[n][1] = (h1) * l_im + (h3) * r_im;
        }
    }
}
