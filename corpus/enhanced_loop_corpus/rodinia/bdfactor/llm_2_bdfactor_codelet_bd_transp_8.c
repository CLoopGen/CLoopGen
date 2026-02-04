#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int lb;
extern int ub;
extern int n1;
extern double **in_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the iteration order and accessing elements in increasing index order
    int start = (ub - i) > 0 ? (ub - i) : 0;
    int end = n1 - lb + i;
    int len = end - (n1 - start) + 1;
    if (len <= 0) return;
    for (int offset = 0; offset < len; offset++) {
        int src_idx = end - offset;
        int dst_idx = n1 - start + offset;
        in_v[i][dst_idx] = in_v[i][src_idx];
    }
}
