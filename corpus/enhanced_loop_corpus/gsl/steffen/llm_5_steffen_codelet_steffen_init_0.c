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
for (i = 0; i < (size - 1); i++) {
    double hi = (x_array[i + 1] - x_array[i]);
    double si = (y_array[i + 1] - y_array[i]) / hi;
    if (hi > 1e-8) {
        a[i] = (y_prime[i] + y_prime[i + 1] - 2 * si) / (hi * hi);
        b[i] = (3 * si - 2 * y_prime[i] - y_prime[i + 1]) / hi;
    } else {
        a[i] = 0.0;
        b[i] = si;
    }
    c[i] = y_prime[i];
    d[i] = y_array[i];
}
}
