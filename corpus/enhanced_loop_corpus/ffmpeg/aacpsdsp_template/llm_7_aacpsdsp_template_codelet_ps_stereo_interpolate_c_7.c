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
INTFLOAT local_h0 = h0;
INTFLOAT local_h1 = h1;
INTFLOAT local_h2 = h2;
INTFLOAT local_h3 = h3;
for (n = 0; n < len; n++) {
    INTFLOAT l_re = l[n][0];
    INTFLOAT l_im = l[n][1];
    INTFLOAT r_re = r[n][0];
    INTFLOAT r_im = r[n][1];
    local_h0 += hs0;
    local_h1 += hs1;
    local_h2 += hs2;
    local_h3 += hs3;
    l[n][0] = (local_h0 * l_re + local_h2 * r_re);
    l[n][1] = (local_h0 * l_im + local_h2 * r_im);
    r[n][0] = (local_h1 * l_re + local_h3 * r_re);
    r[n][1] = (local_h1 * l_im + local_h3 * r_im);
}
h0 = local_h0;
h1 = local_h1;
h2 = local_h2;
h3 = local_h3;
}
