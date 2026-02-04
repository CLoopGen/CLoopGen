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
    long local_tbl[64];
    long local_rnd1 = rnd1;
    long local_rnd2 = rnd2;
    for (i = 0; i < 64; i++) {
        long lx, ly;
        lx = a1 * (local_rnd1 % q1);
        ly = r1 * (local_rnd1 / q1);
        local_rnd1 = lx - ly;
        if (local_rnd1 < 0)
            local_rnd1 += m1;
        lx = a2 * (local_rnd2 % q2);
        ly = r2 * (local_rnd2 / q2);
        local_rnd2 = lx - ly;
        if (local_rnd2 < 0)
            local_rnd2 += m2;
        local_tbl[i] = local_rnd1 - local_rnd2;
        if (local_tbl[i] < 0)
            local_tbl[i] += m1;
    }
    for (i = 0; i < 64; i++) {
        tbl[i] = local_tbl[i];
    }
    rnd1 = local_rnd1;
    rnd2 = local_rnd2;
}
