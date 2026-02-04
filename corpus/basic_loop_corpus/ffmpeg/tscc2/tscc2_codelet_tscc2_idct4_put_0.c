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
    t0 = (((in[0 * 4 + i]) * (q[0 + (i & 1)]) + 128) >> 8);
    t1 = (((in[1 * 4 + i]) * (q[1 + (i & 1)]) + 128) >> 8);
    t2 = (((in[2 * 4 + i]) * (q[0 + (i & 1)]) + 128) >> 8);
    t3 = (((in[3 * 4 + i]) * (q[1 + (i & 1)]) + 128) >> 8);
    tblk[0 * 4 + i] = (5 * ((t0) + (t1) + (t2)) + 2 * (t3));
    tblk[1 * 4 + i] = (5 * ((t0) - (t2) - (t3)) + 2 * (t1));
    tblk[2 * 4 + i] = (5 * ((t0) - (t2) + (t3)) - 2 * (t1));
    tblk[3 * 4 + i] = (5 * ((t0) - (t1) + (t2)) - 2 * (t3));
    ;
}

}
