#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 6; k++) {
        double temp1 = a_work[k + 1];
        double temp2 = a_work[k + 2];
        double coef = alpha[k][k + 1] * 1.05;
        if (temp2 > temp1 * coef + 0.001)
            break;
    }
}
