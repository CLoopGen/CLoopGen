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
    // Variant 1: Strided Memory Access (access every 2nd element, assuming len is even)
    for (n = 0; n < len; n += 2) {
        if (n + 1 >= len) break;
        INTFLOAT l_re1 = l[n][0];
        INTFLOAT l_im1 = l[n][1];
        INTFLOAT r_re1 = r[n][0];
        INTFLOAT r_im1 = r[n][1];
        
        INTFLOAT l_re2 = l[n+1][0];
        INTFLOAT l_im2 = l[n+1][1];
        INTFLOAT r_re2 = r[n+1][0];
        INTFLOAT r_im2 = r[n+1][1];

        h00 += hs00;
        h01 += hs01;
        h02 += hs02;
        h03 += hs03;
        h10 += hs10;
        h11 += hs11;
        h12 += hs12;
        h13 += hs13;

        // Update first element
        l[n][0] = ((h00) * (l_re1) + (h02) * (r_re1) - (h10) * (l_im1) - (h12) * (r_im1));
        l[n][1] = ((h00) * (l_im1) + (h02) * (r_im1) + (h10) * (l_re1) + (h12) * (r_re1));
        r[n][0] = ((h01) * (l_re1) + (h03) * (r_re1) - (h11) * (l_im1) - (h13) * (r_im1));
        r[n][1] = ((h01) * (l_im1) + (h03) * (r_im1) + (h11) * (l_re1) + (h13) * (r_re1));

        // Update second element with same accumulated h values
        l[n+1][0] = ((h00) * (l_re2) + (h02) * (r_re2) - (h10) * (l_im2) - (h12) * (r_im2));
        l[n+1][1] = ((h00) * (l_im2) + (h02) * (r_im2) + (h10) * (l_re2) + (h12) * (r_re2));
        r[n+1][0] = ((h01) * (l_re2) + (h03) * (r_re2) - (h11) * (l_im2) - (h13) * (r_im2));
        r[n+1][1] = ((h01) * (l_im2) + (h03) * (r_im2) + (h11) * (l_re2) + (h13) * (r_re2));
    }
}
