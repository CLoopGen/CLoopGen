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
int step = 2;
for (j = m + 1; j < nmax; j += step) {
    double temp = (x * p_n1 - j * p_n0) * 2 * (j + 1.) / (j - m + 1.);
    p_n0 = p_n1;
    p_n1 = temp;
    result_array[j + 1] = temp;
    
    if (j + 1 < nmax) {
        int k = j + 1;
        temp = (x * p_n1 - k * p_n0) * 2 * (k + 1.) / (k - m + 1.);
        p_n0 = p_n1;
        p_n1 = temp;
        result_array[k + 1] = temp;
    }
}
}
