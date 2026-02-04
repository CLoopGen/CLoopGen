#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern  double x;
extern double *result_array;
extern double Ynp1;
extern double Yn;
extern double Ynm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_Ynm1, prev_Yn, next_Ynp1;
    prev_Ynm1 = Ynm1;
    prev_Yn = Yn;
    for (n = nmin + 1; n <= nmax + 1; n++) {
        result_array[n - nmin - 1] = prev_Ynm1;
        next_Ynp1 = -prev_Ynm1 + 2. * n / x * prev_Yn;
        prev_Ynm1 = prev_Yn;
        prev_Yn = next_Ynp1;
    }
    Ynm1 = prev_Ynm1;
    Yn = prev_Yn;
}
