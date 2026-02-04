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
    // Variant 2: Strided memory access with reverse traversal (stride of -2)
    // This variant accesses array elements in reverse order with a step size of 2
    // Assumes len is positive and adjusts starting point accordingly
    int start = (len % 2 == 1) ? len - 1 : len - 2;
    for (n = start; n >= 0; n -= 2) {
        INTFLOAT l_re = l[n][0];
        INTFLOAT l_im = l[n][1];
        INTFLOAT r_re = r[n][0];
        INTFLOAT r_im = r[n][1];

        h00 += hs00;
        h01 += hs01;
        h02 += hs02;
        h03 += hs03;
        h10 += hs10;
        h11 += hs11;
        h12 += hs12;
        h13 += hs13;

        l[n][0] = ((h00) * (l_re) + (h02) * (r_re) - (h10) * (l_im) - (h12) * (r_im));
        l[n][1] = ((h00) * (l_im) + (h02) * (r_im) + (h10) * (l_re) + (h12) * (r_re));
        r[n][0] = ((h01) * (l_re) + (h03) * (r_re) - (h11) * (l_im) - (h13) * (r_im));
        r[n][1] = ((h01) * (l_im) + (h03) * (r_im) + (h11) * (l_re) + (h13) * (r_re));

        // Process intermediate element if within bounds
        if (n > 0) {
            int m = n - 1;
            INTFLOAT l_rem = l[m][0], l_imm = l[m][1];
            INTFLOAT r_rem = r[m][0], r_imm = r[m][1];

            // Accumulate h values again as per original logic (one per element)
            h00 += hs00;
            h01 += hs01;
            h02 += hs02;
            h03 += hs03;
            h10 += hs10;
            h11 += hs11;
            h12 += hs12;
            h13 += hs13;

            l[m][0] = ((h00) * (l_rem) + (h02) * (r_rem) - (h10) * (l_imm) - (h12) * (r_imm));
            l[m][1] = ((h00) * (l_imm) + (h02) * (r_imm) + (h10) * (l_rem) + (h12) * (r_rem));
            r[m][0] = ((h01) * (l_rem) + (h03) * (r_rem) - (h11) * (l_imm) - (h13) * (r_imm));
            r[m][1] = ((h01) * (l_imm) + (h03) * (r_imm) + (h11) * (l_rem) + (h13) * (r_rem));
        }
    }
}
