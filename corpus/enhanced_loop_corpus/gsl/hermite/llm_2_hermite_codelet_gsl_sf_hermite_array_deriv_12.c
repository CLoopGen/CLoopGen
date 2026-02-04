#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  int nmax;
extern  double x;
extern double *result_array;
extern double p_n0;
extern double p_n1;
extern double p_n;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by shifting the base pointer to create a view starting at index m+1
    double *base_result = result_array + (m + 1);
    double p_n_local = p_n;
    double p_n0_local = p_n0;
    double p_n1_local = p_n1;
    int len = nmax - (m + 1);
    for (int k = 0; k < len; ++k) {
        p_n_local = (x * p_n1_local - (k + m + 1) * p_n0_local) * 2 * (k + m + 2.) / (k + 2.);
        p_n0_local = p_n1_local;
        p_n1_local = p_n_local;
        base_result[k + 1] = p_n_local;
    }
    // Update the external state variables
    p_n0 = p_n0_local;
    p_n1 = p_n1_local;
    p_n = p_n_local;
}
