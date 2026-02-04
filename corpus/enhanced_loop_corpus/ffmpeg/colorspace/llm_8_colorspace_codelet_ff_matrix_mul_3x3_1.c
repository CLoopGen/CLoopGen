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
    for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
            double sum = 0.0;
            for (int k = 0; k < 3; k++) {
                sum += src2[m][k] * src1[k][n];
            }
            dst[m][n] = sum;
        }
    }
}
