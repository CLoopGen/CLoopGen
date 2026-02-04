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
for (n = 0; n < len; n++) {
    INTFLOAT l_re = l[n][0];
    INTFLOAT l_im = l[n][1];
    INTFLOAT r_re = r[n][0];
    INTFLOAT r_im = r[n][1];
    h0 += hs0;
    h1 += hs1;
    h2 += hs2;
    h3 += hs3;

    if (n % 2 == 0) {
        l[n][0] = (int)((((int64_t)(h0) * (l_re)) + ((int64_t)(h2) * (r_re)) + 536870912) >> 30);
        l[n][1] = (int)((((int64_t)(h0) * (l_im)) + ((int64_t)(h2) * (r_im)) + 536870912) >> 30);
        r[n][0] = (int)((((int64_t)(h1) * (l_re)) + ((int64_t)(h3) * (r_re)) + 536870912) >> 30);
        r[n][1] = (int)((((int64_t)(h1) * (l_im)) + ((int64_t)(h3) * (r_im)) + 536870912) >> 30);
    } else {
        l[n][0] = (int)((((int64_t)(h1) * (l_re)) + ((int64_t)(h3) * (r_re)) + 536870912) >> 30);
        l[n][1] = (int)((((int64_t)(h1) * (l_im)) + ((int64_t)(h3) * (r_im)) + 536870912) >> 30);
        r[n][0] = (int)((((int64_t)(h0) * (l_re)) + ((int64_t)(h2) * (r_re)) + 536870912) >> 30);
        r[n][1] = (int)((((int64_t)(h0) * (l_im)) + ((int64_t)(h2) * (r_im)) + 536870912) >> 30);
    }
}
}
