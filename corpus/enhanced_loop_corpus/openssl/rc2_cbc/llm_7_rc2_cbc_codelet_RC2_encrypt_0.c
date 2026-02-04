#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern int n;
extern RC2_INT *p0;
extern RC2_INT *p1;
extern RC2_INT x0;
extern RC2_INT x1;
extern RC2_INT x2;
extern RC2_INT x3;
extern RC2_INT t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    RC2_INT t0, t1, t2, t3;
    t0 = (x0 + (x1 & ~x3) + (x2 & x3) + *(p0++)) & 65535;
    t1 = (x1 + (x2 & ~x0) + (x3 & x0) + *(p0++)) & 65535;
    t2 = (x2 + (x3 & ~x1) + (x0 & x1) + *(p0++)) & 65535;
    t3 = (x3 + (x0 & ~x2) + (x1 & x2) + *(p0++)) & 65535;  // All t values computed before any update — removed immediate WAW/RAW dependencies

    x0 = (t0 << 1) | (t0 >> 15);
    x1 = (t1 << 2) | (t1 >> 14);
    x2 = (t2 << 3) | (t2 >> 13);
    x3 = (t3 << 5) | (t3 >> 11);  // All updates happen after all computations — eliminated intra-iteration data dependencies

    if (--i == 0) {
        if (--n == 0)
            break;
        i = (n == 2) ? 6 : 5;
        x0 += p1[x3 & 63];
        x1 += p1[x0 & 63];
        x2 += p1[x1 & 63];
        x3 += p1[x2 & 63];
    }
}
}
