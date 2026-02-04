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
    // Variant 1: Increased computational intensity by unrolling the loop and adding extra arithmetic operations
    // Also reduces effective trip count by processing two iterations per loop cycle
    int n = nmax;
    while (n >= nmin + 1) {
        // First iteration of unrolled loop
        result_array[n - nmin] = In;
        Inm1 = Inp1 + n * two_over_x * In;
        Inp1 = In;
        In = Inm1;

        // Second iteration with additional arithmetic to increase complexity
        n--;
        result_array[n - nmin] = In;
        Inm1 = Inp1 + n * two_over_x * In + (Inp1 * In * 0.1); // Extra term added
        Inp1 = In;
        In = Inm1;

        n--;
    }
    // Handle remaining iteration if trip count is odd
    if (n == nmin) {
        result_array[n - nmin] = In;
        Inm1 = Inp1 + n * two_over_x * In;
        Inp1 = In;
        In = Inm1;
    }
}
