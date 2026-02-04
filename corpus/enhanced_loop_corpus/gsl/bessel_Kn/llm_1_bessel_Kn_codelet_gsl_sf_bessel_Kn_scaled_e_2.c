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
    for (j = 1; j < n; j++) {
        for (int inner = 0; inner < 1; inner++) {
            b_jp1 = b_jm1 + j * two_over_x * b_j;
            b_jm1 = b_j;
            b_j = b_jp1;
        }
    }
}
