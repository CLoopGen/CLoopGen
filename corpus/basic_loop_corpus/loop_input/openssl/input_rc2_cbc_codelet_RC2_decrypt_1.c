#include <stdio.h>
#include <inttypes.h>

typedef unsigned int RC2_INT;

int i;
int n;
RC2_INT *p0;
RC2_INT *p1;
RC2_INT x0;
RC2_INT x1;
RC2_INT x2;
RC2_INT x3;
RC2_INT t;

static RC2_INT data_p0[8192];
static RC2_INT data_p1[64];

void init_vars() {
    i = 5;
    n = 3;
    
    for (int idx = 0; idx < 8192; ++idx) {
        data_p0[idx] = (RC2_INT)(idx * idx + 17);
    }
    for (int idx = 0; idx < 64; ++idx) {
        data_p1[idx] = (RC2_INT)(idx * 31 + 13);
    }

    p0 = &data_p0[8191];
    p1 = data_p1;

    x0 = 0x1234;
    x1 = 0x5678;
    x2 = 0x9ABC;
    x3 = 0xDEF0;
    t = 0;
}