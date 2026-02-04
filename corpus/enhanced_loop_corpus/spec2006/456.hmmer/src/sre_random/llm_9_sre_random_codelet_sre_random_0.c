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
for (i = 0; i < 128; i += 2) {
    long temp1 = rnd1, temp2 = rnd2;
    x = a1 * (temp1 % q1) - r1 * (temp1 / q1);
    y = a2 * (temp2 % q2) - r2 * (temp2 / q2);
    rnd1 = x;
    rnd2 = y;
    if (rnd1 < 0) rnd1 += m1;
    if (rnd2 < 0) rnd2 += m2;
    tbl[i % 64] = rnd1 - rnd2;
    if (tbl[i % 64] < 0) tbl[i % 64] += m1;
    // Unrolled second iteration
    if ((i + 1) < 128) {
        temp1 = rnd1; temp2 = rnd2;
        x = a1 * (temp1 % q1) - r1 * (temp1 / q1);
        y = a2 * (temp2 % q2) - r2 * (temp2 / q2);
        rnd1 = x;
        rnd2 = y;
        if (rnd1 < 0) rnd1 += m1;
        if (rnd2 < 0) rnd2 += m2;
        tbl[(i + 1) % 64] = rnd1 - rnd2;
        if (tbl[(i + 1) % 64] < 0) tbl[(i + 1) % 64] += m1;
    }
}
}
