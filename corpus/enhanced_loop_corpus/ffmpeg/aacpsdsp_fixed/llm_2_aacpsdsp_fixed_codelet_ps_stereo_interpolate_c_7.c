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
        if (n + 1 >= len) break;
        INTFLOAT l_re0 = l[n][0];
        INTFLOAT l_im0 = l[n][1];
        INTFLOAT r_re0 = r[n][0];
        INTFLOAT r_im0 = r[n][1];
        INTFLOAT l_re1 = l[n+1][0];
        INTFLOAT l_im1 = l[n+1][1];
        INTFLOAT r_re1 = r[n+1][0];
        INTFLOAT r_im1 = r[n+1][1];

        h0 += hs0; h1 += hs1; h2 += hs2; h3 += hs3;
        INTFLOAT temp_h0 = h0, temp_h1 = h1, temp_h2 = h2, temp_h3 = h3;

        l[n][0] = (int)((((int64_t)(temp_h0) * (l_re0)) + ((int64_t)(temp_h2) * (r_re0)) + 536870912) >> 30);
        l[n][1] = (int)((((int64_t)(temp_h0) * (l_im0)) + ((int64_t)(temp_h2) * (r_im0)) + 536870912) >> 30);
        r[n][0] = (int)((((int64_t)(temp_h1) * (l_re0)) + ((int64_t)(temp_h3) * (r_re0)) + 536870912) >> 30);
        r[n][1] = (int)((((int64_t)(temp_h1) * (l_im0)) + ((int64_t)(temp_h3) * (r_im0)) + 536870912) >> 30);

        h0 += hs0; h1 += hs1; h2 += hs2; h3 += hs3;
        l[n+1][0] = (int)((((int64_t)(h0) * (l_re1)) + ((int64_t)(h2) * (r_re1)) + 536870912) >> 30);
        l[n+1][1] = (int)((((int64_t)(h0) * (l_im1)) + ((int64_t)(h2) * (r_im1)) + 536870912) >> 30);
        r[n+1][0] = (int)((((int64_t)(h1) * (l_re1)) + ((int64_t)(h3) * (r_re1)) + 536870912) >> 30);
        r[n+1][1] = (int)((((int64_t)(h1) * (l_im1)) + ((int64_t)(h3) * (r_im1)) + 536870912) >> 30);
    }
}
