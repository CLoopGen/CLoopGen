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
    long temp_rnd1 = rnd1;
    long temp_rnd2 = rnd2;
    for (i = 0; i < 64; i++) {
        x = a1 * (temp_rnd1 % q1);
        y = r1 * (temp_rnd1 / q1);
        temp_rnd1 = x - y;
        if (temp_rnd1 < 0)
            temp_rnd1 += m1;
        x = a2 * (temp_rnd2 % q2);
        y = r2 * (temp_rnd2 / q2);
        temp_rnd2 = x - y;
        if (temp_rnd2 < 0)
            temp_rnd2 += m2;
        tbl[i] = temp_rnd1 - temp_rnd2;
        if (tbl[i] < 0)
            tbl[i] += m1;
    }
    rnd1 = temp_rnd1;
    rnd2 = temp_rnd2;
}
