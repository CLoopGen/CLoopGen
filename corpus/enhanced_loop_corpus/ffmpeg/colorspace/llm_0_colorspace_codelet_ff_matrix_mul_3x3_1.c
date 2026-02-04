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
for (m = 0; m < 3; m++)
    for (n = 0; n < 3; n++)
        for (int k = 0; k < 1; k++)
            dst[m][n] = src2[m][0] * src1[0][n] + src2[m][1] * src1[1][n] + src2[m][2] * src1[2][n];
}
