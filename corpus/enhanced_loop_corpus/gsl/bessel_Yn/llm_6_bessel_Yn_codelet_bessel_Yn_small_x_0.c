#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    double prev_k_term = k_term;
    for (k = 1; k <= n - 1; k++) {
        double local_y = y;
        double denominator = (k * (n - k));
        k_term = prev_k_term * local_y / denominator;
        temp_sum += k_term;
        prev_k_term = k_term;
    }
    sum1 += temp_sum;
}
