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
    double temp_b_jm1 = b_jm1;
    double temp_b_j = b_j;
    for (j = 1; j < n; j++) {
        double temp_b_jp1 = temp_b_jm1 + j * two_over_x * temp_b_j;
        temp_b_jm1 = temp_b_j;
        temp_b_j = temp_b_jp1;
    }
    b_jm1 = temp_b_jm1;
    b_j = temp_b_j;
}
