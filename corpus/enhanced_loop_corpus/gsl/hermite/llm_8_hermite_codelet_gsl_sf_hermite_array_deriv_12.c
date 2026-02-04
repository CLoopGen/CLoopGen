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
for (j = m + 1; j < nmax; ++j) {
    p_n = x * p_n1;
    p_n -= j * p_n0;
    p_n *= 2.0 * (j + 1.0);
    p_n /= (j - m + 1.0);
    p_n0 = p_n1;
    p_n1 = p_n;
    result_array[j + 1] = p_n;
}
}
