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
    double prev_prev = b_jm1;
    double prev = b_j;
    double current;
    for (j = 1; j < n; j++) {
        if (j == 1) {
            current = prev_prev + j * two_over_x * prev;
        } else {
            double temp = prev_prev + j * two_over_x * prev;
            prev_prev = prev;
            prev = current;
            current = temp;
        }
    }
    if (n > 1) {
        b_jm1 = prev;
        b_j = current;
    }
}
