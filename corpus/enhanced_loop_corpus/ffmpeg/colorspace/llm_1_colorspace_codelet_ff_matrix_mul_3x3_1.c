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
    dst[m][0] = src2[m][0] * src1[0][0] + src2[m][1] * src1[1][0] + src2[m][2] * src1[2][0];
for (m = 0; m < 3; m++)
    dst[m][1] = src2[m][0] * src1[0][1] + src2[m][1] * src1[1][1] + src2[m][2] * src1[2][1];
for (m = 0; m < 3; m++)
    dst[m][2] = src2[m][0] * src1[0][2] + src2[m][1] * src1[1][2] + src2[m][2] * src1[2][2];
}
