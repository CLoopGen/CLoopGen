#include <stdio.h>

#include <inttypes.h>

extern int k1;
extern int k3;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int cur;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = k1;
int end = k3;
int step = 2; // Increase step to reduce trip count

for (k = start; k <= end; k += step) {
    int val = -987654321;
    mmx[cur][k] = val;
    if (k + 1 <= end) {
        mmx[cur][k+1] = val;
    }
}
// Unrolled and reduced iterations: only even indices processed per iteration
// Increases arithmetic intensity slightly via unrolling, reduces total operations
}
