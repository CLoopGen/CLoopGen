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
for (n = 0; n < len; n += 2) {
    INTFLOAT l_re0 = l[n][0];
    INTFLOAT l_im0 = l[n][1];
    INTFLOAT r_re0 = r[n][0];
    INTFLOAT r_im0 = r[n][1];
    h0 += hs0;
    h1 += hs1;
    h2 += hs2;
    h3 += hs3;
    l[n][0] = ((h0) * (l_re0) + (h2) * (r_re0));
    l[n][1] = ((h0) * (l_im0) + (h2) * (r_im0));
    r[n][0] = ((h1) * (l_re0) + (h3) * (r_re0));
    r[n][1] = ((h1) * (l_im0) + (h3) * (r_im0));

    if (n + 1 < len) {
        INTFLOAT l_re1 = l[n+1][0];
        INTFLOAT l_im1 = l[n+1][1];
        INTFLOAT r_re1 = r[n+1][0];
        INTFLOAT r_im1 = r[n+1][1];
        h0 += hs0;
        h1 += hs1;
        h2 += hs2;
        h3 += hs3;
        l[n+1][0] = ((h0) * (l_re1) + (h2) * (r_re1));
        l[n+1][1] = ((h0) * (l_im1) + (h2) * (r_im1));
        r[n+1][0] = ((h1) * (l_re1) + (h3) * (r_re1));
        r[n+1][1] = ((h1) * (l_im1) + (h3) * (r_im1));
    }
}
}
