#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in;
extern int q[3];
extern int i;
extern int tblk[16];
extern int t0;
extern int t1;
extern int t2;
extern int t3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    int idx = i % 4;
    t0 = (((in[0 * 4 + idx]) * (q[0]) + 256) >> 9);
    t1 = (((in[1 * 4 + idx]) * (q[1]) + 256) >> 9);
    t2 = (((in[2 * 4 + idx]) * (q[0]) + 256) >> 9);
    t3 = (((in[3 * 4 + idx]) * (q[1]) + 256) >> 9);

    int sum_tt = t0 + t1 + t2 + t3;
    int diff_tt = t0 - t1 - t2 - t3;

    tblk[0 * 4 + idx] = (7 * sum_tt + 3 * (t0 + t2));
    tblk[1 * 4 + idx] = (7 * diff_tt + 3 * (t1 + t3));
    if (i + 1 < 8) {
        tblk[0 * 4 + ((idx + 1) % 4)] = (7 * (t0 + t1) - 3 * (t2 + t3));
        tblk[1 * 4 + ((idx + 1) % 4)] = (7 * (t0 - t3) + 3 * (t1 - t2));
    }
}
}
