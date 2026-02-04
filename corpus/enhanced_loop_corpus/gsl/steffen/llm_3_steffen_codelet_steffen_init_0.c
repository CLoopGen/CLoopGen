#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x_array[];
extern  double y_array[];
extern size_t size;
extern size_t i;
extern double *a;
extern double *b;
extern double *c;
extern double *d;
extern double *y_prime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Sequential Access (processing array from end to beginning)
    for (i = size - 2; ; i--) {
        double hi = (x_array[i + 1] - x_array[i]);
        double si = (y_array[i + 1] - y_array[i]) / hi;
        a[i] = (y_prime[i] + y_prime[i + 1] - 2 * si) / hi / hi;
        b[i] = (3 * si - 2 * y_prime[i] - y_prime[i + 1]) / hi;
        c[i] = y_prime[i];
        d[i] = y_array[i];
        
        if (i == 0) break;
    }
}
