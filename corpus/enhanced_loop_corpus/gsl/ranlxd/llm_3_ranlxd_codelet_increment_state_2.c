#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double one_bit;
extern int k;
extern int kmax;
extern double _usr_y1;
extern double y2;
extern double *xdbl;
extern double carry;
extern unsigned int ir;
extern unsigned int jr;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
for (; k < kmax; ++k) {
    int step = 2;
    int limited_k = k % 6; // Ensure indices stay within bounds for demonstration
    int src_idx = (jr + limited_k * step) % 12;
    int dst_idx = (ir + limited_k * step) % 12;
    y1 = xdbl[src_idx] - xdbl[dst_idx];
    y2 = y1 - carry;
    if (y2 < 0) {
        carry = one_bit;
        y2 += 1;
    } else {
        carry = 0;
    }
    xdbl[dst_idx] = y2;
    ir = next[ir];
    jr = next[jr];
}
}
