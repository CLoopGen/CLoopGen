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
for (i = 0; i < 4; i++) {
    int index = (i & 1);
    t0 = (((in[0 * 4 + i]) * (q[0 + index]) + 128) >> 8);
    t1 = (((in[1 * 4 + i]) * (q[1 + index]) + 128) >> 8);
    t2 = (((in[2 * 4 + i]) * (q[0 + index]) + 128) >> 8);
    t3 = (((in[3 * 4 + i]) * (q[1 + index]) + 128) >> 8);

    int sum1 = (t0) + (t1) + (t2);
    int sum2 = (t0) - (t2) - (t3);
    int sum3 = (t0) - (t2) + (t3);
    int sum4 = (t0) - (t1) + (t2);

    if (sum1 > 0 || sum4 > 0) {
        tblk[0 * 4 + i] = (5 * sum1 + 2 * (t3));
        tblk[3 * 4 + i] = (5 * sum4 - 2 * (t3));
    } else {
        tblk[0 * 4 + i] = 0;
        tblk[3 * 4 + i] = 0;
    }

    if (sum2 >= 0) {
        tblk[1 * 4 + i] = (5 * sum2 + 2 * (t1));
    } else {
        tblk[1 * 4 + i] = (5 * sum2 - 2 * (t1)); // Modified behavior on sign
    }

    if (sum3 < 0) {
        tblk[2 * 4 + i] = -(5 * (-sum3) - 2 * (t1));
    } else {
        tblk[2 * 4 + i] = (5 * sum3 - 2 * (t1));
    }
}
}
