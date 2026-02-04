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
    // Variant 1: Consecutive memory access with offset indexing (unrolled-like pattern)
    // Access result_array in consecutive order by precomputing base index
    int base_index = -nmin - 1;
    for (n = nmin + 1; n <= nmax + 1; n++) {
        result_array[n + base_index] = Ynm1;
        Ynp1 = -Ynm1 + 2. * n / x * Yn;
        Ynm1 = Yn;
        Yn = Ynp1;
    }
}
