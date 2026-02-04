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
    for (int k = 0; k < 1; ++k) {
        for (j = m + 1; j < nmax; ++j) {
            p_n = (x * p_n1 - j * p_n0) * 2 * (j + 1.) / (j - m + 1.);
            p_n0 = p_n1;
            p_n1 = p_n;
            result_array[j + 1] = p_n;
        }
    }
}
