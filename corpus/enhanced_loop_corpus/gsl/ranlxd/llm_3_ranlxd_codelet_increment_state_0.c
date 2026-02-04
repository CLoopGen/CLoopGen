#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double one_bit;
extern int k;
extern double _usr_y1;
extern double y2;
extern double *xdbl;
extern double carry;
extern unsigned int ir;
extern unsigned int jr;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
// Variant with strided memory access: instead of chasing linked-list-like 'next' pointers,
// access xdbl with a fixed stride (e.g., every second element), simulating regular pattern.
int stride = 2;
int limit = 1000; // Prevent infinite loop by bounding iterations
for (k = 0; k < limit && ir > 0 && jr > 0; ++k) {
    int idx_i = ir % 50; // Simulate bounded array indices for predictable strided access
    int idx_j = jr % 50;
    y1 = xdbl[idx_j] - xdbl[idx_i];
    y2 = y1 - carry;
    if (y2 < 0) {
        carry = one_bit;
        y2 += 1;
    } else {
        carry = 0;
    }
    xdbl[idx_i] = y2;
    // Stride-based progression instead of indirect via next[]
    ir = (ir + stride) % 50;
    jr = (jr + stride) % 50;
}
}
