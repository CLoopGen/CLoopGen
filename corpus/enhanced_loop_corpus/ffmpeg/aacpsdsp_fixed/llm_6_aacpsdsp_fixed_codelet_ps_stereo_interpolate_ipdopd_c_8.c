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



void loop() {
    for (n = 0; n < len; n++) {
        INTFLOAT l_re = l[n][0];
        INTFLOAT l_im = l[n][1];
        INTFLOAT r_re = r[n][0];
        INTFLOAT r_im = r[n][1];

        // Introduce temporary accumulators to break direct WAW dependencies on hxx
        INTFLOAT temp_h00 = h00 + hs00;
        INTFLOAT temp_h01 = h01 + hs01;
        INTFLOAT temp_h02 = h02 + hs02;
        INTFLOAT temp_h03 = h03 + hs03;
        INTFLOAT temp_h10 = h10 + hs10;
        INTFLOAT temp_h11 = h11 + hs11;
        INTFLOAT temp_h12 = h12 + hs12;
        INTFLOAT temp_h13 = h13 + hs13;

        // Delay update of global hxx until after computation to remove RAW hazard
        l[n][0] = (int)((((int64_t)(h00) * (l_re)) + ((int64_t)(h02) * (r_re)) - ((int64_t)(h10) * (l_im)) - ((int64_t)(h12) * (r_im)) + 536870912) >> 30);
        l[n][1] = (int)((((int64_t)(h00) * (l_im)) + ((int64_t)(h02) * (r_im)) + ((int64_t)(h10) * (l_re)) + ((int64_t)(h12) * (r_re)) + 536870912) >> 30);
        r[n][0] = (int)((((int64_t)(h01) * (l_re)) + ((int64_t)(h03) * (r_re)) - ((int64_t)(h11) * (l_im)) - ((int64_t)(h13) * (r_im)) + 536870912) >> 30);
        r[n][1] = (int)((((int64_t)(h01) * (l_im)) + ((int64_t)(h03) * (r_im)) + ((int64_t)(h11) * (l_re)) + ((int64_t)(h13) * (r_re)) + 536870912) >> 30);

        // Update hxx only at the end to eliminate potential loop-carried WAR dependency
        h00 = temp_h00;
        h01 = temp_h01;
        h02 = temp_h02;
        h03 = temp_h03;
        h10 = temp_h10;
        h11 = temp_h11;
        h12 = temp_h12;
        h13 = temp_h13;
    }
}
