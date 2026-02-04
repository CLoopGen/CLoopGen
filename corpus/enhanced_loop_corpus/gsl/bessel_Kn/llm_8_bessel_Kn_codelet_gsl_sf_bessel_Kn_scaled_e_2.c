#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double two_over_x;
extern double b_jm1;
extern double b_j;
extern double b_jp1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j < n; j += 2) {
        if (j + 1 < n) {
            double temp1 = b_jm1 + j * two_over_x * b_j;
            double temp2 = b_j + (j + 1) * two_over_x * temp1;
            b_jm1 = temp1;
            b_j = temp2;
            b_jp1 = temp2;
        } else {
            b_jp1 = b_jm1 + j * two_over_x * b_j;
            b_jm1 = b_j;
            b_j = b_jp1;
        }
    }
}
