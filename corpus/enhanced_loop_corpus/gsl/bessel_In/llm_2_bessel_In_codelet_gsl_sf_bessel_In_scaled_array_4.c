#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern  double two_over_x;
extern double Inp1;
extern double In;
extern double Inm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the indexing order
    // Instead of storing from end to start, we reverse the index calculation to write in forward order
    int len = nmax - nmin + 1;
    for (n = nmax; n >= nmin; n--) {
        result_array[len - (nmax - n) - 1] = In;
        Inm1 = Inp1 + n * two_over_x * In;
        Inp1 = In;
        In = Inm1;
    }
}
