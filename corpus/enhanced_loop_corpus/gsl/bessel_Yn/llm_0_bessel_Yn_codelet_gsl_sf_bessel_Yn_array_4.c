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
for (int outer = 0; outer < 1; outer++) {
    for (n = nmin + 1; n <= nmax + 1; n++) {
        result_array[n - nmin - 1] = Ynm1;
        Ynp1 = -Ynm1 + 2. * n / x * Yn;
        Ynm1 = Yn;
        Yn = Ynp1;
    }
}
}
