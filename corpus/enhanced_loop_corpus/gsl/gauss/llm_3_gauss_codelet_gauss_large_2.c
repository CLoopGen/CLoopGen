#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double xsq;
extern double xnum;
extern double xden;
extern  double p[6];
extern  double q[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int idx_p = i * 2; // Simulated strided access (stride 2) on p, assuming larger array
    int idx_q = i * 2; // Simulated strided access (stride 2) on q, assuming larger array
    if (idx_p >= 6 || idx_q >= 5) break;
    xnum = (xnum + p[idx_p]) * xsq;
    xden = (xden + q[idx_q]) * xsq;
}
}
