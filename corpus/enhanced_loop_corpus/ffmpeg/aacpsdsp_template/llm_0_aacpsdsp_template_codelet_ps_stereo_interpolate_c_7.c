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
    for (int outer = 0; outer < len; outer += 2) {
        for (int inner = outer; inner < outer + 2 && inner < len; inner++) {
            INTFLOAT l_re = l[inner][0];
            INTFLOAT l_im = l[inner][1];
            INTFLOAT r_re = r[inner][0];
            INTFLOAT r_im = r[inner][1];
            h0 += hs0;
            h1 += hs1;
            h2 += hs2;
            h3 += hs3;
            l[inner][0] = ((h0) * (l_re) + (h2) * (r_re));
            l[inner][1] = ((h0) * (l_im) + (h2) * (r_im));
            r[inner][0] = ((h1) * (l_re) + (h3) * (r_re));
            r[inner][1] = ((h1) * (l_im) + (h3) * (r_im));
        }
    }
}
