#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double x;
extern double sum;
extern double term;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_term = term;
    double local_sum = sum;
    for (k = 1; k < N; k++) {
        local_term *= (N - k) / x;
        local_sum += local_term;
        term = local_term; // WAW dependency introduced: write-after-write on shared 'term'
        sum = local_sum;   // Update shared 'sum' inside loop (WAW)
    }
}
