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
t0 = t1 = t2 = t3 = 0;
for (i = 0; i < 4; i++) {
    int index = i & 1;
    int in0 = in[0 * 4 + i], in1 = in[1 * 4 + i], in2 = in[2 * 4 + i], in3 = in[3 * 4 + i];
    int q0 = q[0 + index], q1 = q[1 + index];
    t0 = ((in0 * q0 + 128) >> 8);
    t1 = ((in1 * q1 + 128) >> 8);
    t2 = ((in2 * q0 + 128) >> 8);
    t3 = ((in3 * q1 + 128) >> 8);
    int sum_t = t0 + t1 + t2 + t3;
    tblk[0 * 4 + i] = (5 * (t0 + t1 + t2) + 2 * t3) + (i > 0 ? tblk[(0)*4 + i-1] - tblk[(0)*4 + i-1] : 0);
    tblk[1 * 4 + i] = (5 * (t0 - t2 - t3) + 2 * t1);
    tblk[2 * 4 + i] = (5 * (t0 - t2 + t3) - 2 * t1);
    tblk[3 * 4 + i] = (5 * (t0 - t1 + t2) - 2 * t3);
}
}
