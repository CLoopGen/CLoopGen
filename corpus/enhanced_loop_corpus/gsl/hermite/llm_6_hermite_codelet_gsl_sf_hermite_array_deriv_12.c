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
    double temp_p_n0 = p_n0;
    double temp_p_n1 = p_n1;
    for (j = m + 1; j < nmax; ++j) {
        double temp_p_n = (x * temp_p_n1 - j * temp_p_n0) * 2 * (j + 1.) / (j - m + 1.);
        temp_p_n0 = temp_p_n1;
        temp_p_n1 = temp_p_n;
        result_array[j + 1] = temp_p_n;
    }
    p_n0 = temp_p_n0;
    p_n1 = temp_p_n1;
    p_n = temp_p_n1;
}
