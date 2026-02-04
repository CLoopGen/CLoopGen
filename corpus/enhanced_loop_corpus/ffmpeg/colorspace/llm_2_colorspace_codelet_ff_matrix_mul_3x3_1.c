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
    // Variant 1: Memory Access Pattern Modification - Strided Access with Transposed Indexing
    // We modify access to src1 by transposing its indices in computation, creating a strided memory access pattern
    // This changes the original row-major access of src1[i][j] to effectively access column-major like src1[j][i]
    for (m = 0; m < 3; m++)
        for (n = 0; n < 3; n++)
            dst[m][n] = src2[m][0] * src1[n][0] + src2[m][1] * src1[n][1] + src2[m][2] * src1[n][2];
}
