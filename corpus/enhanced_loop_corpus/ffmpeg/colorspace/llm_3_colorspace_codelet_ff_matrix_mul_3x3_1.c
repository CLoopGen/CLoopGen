#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dst[3][3];
extern  double src1[3][3];
extern  double src2[3][3];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Sequential Access via Linear Indexing
    // Convert 2D array accesses into linearized consecutive memory accesses using pointer arithmetic
    // This improves spatial locality and reflects a flat, consecutive memory traversal pattern
    double *d = &dst[0][0];
    double *s2 = &src2[0][0];
    double *s1 = &src1[0][0];
    
    for (m = 0; m < 3; m++) {
        int m3 = m * 3;
        for (n = 0; n < 3; n++) {
            int idx = m3 + n;
            d[idx] = s2[m3 + 0] * s1[0 + n] + s2[m3 + 1] * s1[3 + n] + s2[m3 + 2] * s1[6 + n];
        }
    }
}
