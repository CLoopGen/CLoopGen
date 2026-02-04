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
    if (len > 0) {
        for (n = 0; n < len; n++) {
            INTFLOAT l_re = l[n][0];
            INTFLOAT l_im = l[n][1];
            INTFLOAT r_re = r[n][0];
            INTFLOAT r_im = r[n][1];
            for (int update = 0; update < 1; update++) {
                h00 += hs00;
                h01 += hs01;
                h02 += hs02;
                h03 += hs03;
                h10 += hs10;
                h11 += hs11;
                h12 += hs12;
                h13 += hs13;
            }
            l[n][0] = (int)((((int64_t)(h00) * (l_re)) + ((int64_t)(h02) * (r_re)) - ((int64_t)(h10) * (l_im)) - ((int64_t)(h12) * (r_im)) + 536870912) >> 30);
            l[n][1] = (int)((((int64_t)(h00) * (l_im)) + ((int64_t)(h02) * (r_im)) + ((int64_t)(h10) * (l_re)) + ((int64_t)(h12) * (r_re)) + 536870912) >> 30);
            r[n][0] = (int)((((int64_t)(h01) * (l_re)) + ((int64_t)(h03) * (r_re)) - ((int64_t)(h11) * (l_im)) - ((int64_t)(h13) * (r_im)) + 536870912) >> 30);
            r[n][1] = (int)((((int64_t)(h01) * (l_im)) + ((int64_t)(h03) * (r_im)) + ((int64_t)(h11) * (l_re)) + ((int64_t)(h13) * (r_re)) + 536870912) >> 30);
        }
    }
}
