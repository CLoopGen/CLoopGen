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
    double prev_p_n0 = p_n0;
    double prev_p_n1 = p_n1;
    double current_p_n;
    for (j = m + 1; j < nmax; ++j) {
        current_p_n = (x * prev_p_n1 - j * prev_p_n0) * 2 * (j + 1.) / (j - m + 1.);
        result_array[j + 1] = current_p_n;
        if (j > m + 1) {
            prev_p_n0 = prev_p_n1;
        }
        prev_p_n1 = current_p_n;
    }
    p_n0 = prev_p_n0;
    p_n1 = prev_p_n1;
    p_n = current_p_n;
}
