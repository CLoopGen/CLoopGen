#include <stdio.h>

#include <inttypes.h>

extern long rnd1;
extern long rnd2;
extern long tbl[64];
extern long x;
extern long y;
extern int i;
extern long a1;
extern long m1;
extern long q1;
extern long r1;
extern long a2;
extern long m2;
extern long q2;
extern long r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    x = a1 * (rnd1 % q1);
    y = r1 * (rnd1 / q1);
    rnd1 = x - y;
    if (rnd1 < 0)
        rnd1 += m1;
    x = a2 * (rnd2 % q2);
    y = r2 * (rnd2 / q2);
    rnd2 = x - y;
    if (rnd2 < 0)
        rnd2 += m2;
    tbl[63 - i] = rnd1 - rnd2;
    if (tbl[63 - i] < 0)
        tbl[63 - i] += m1;
}
}
