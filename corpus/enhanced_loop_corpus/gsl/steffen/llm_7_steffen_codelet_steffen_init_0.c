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
double prev_hi = 0.0, prev_si = 0.0;
for (i = 0; i < (size - 1); i++) {
    double hi = (x_array[i + 1] - x_array[i]);
    double si = (y_array[i + 1] - y_array[i]) / hi;
    if (i > 0) {
        a[i-1] = (y_prime[i] + y_prime[i] - 2 * prev_si) / prev_hi / prev_hi;
        b[i-1] = (3 * prev_si - 2 * y_prime[i] - y_prime[i]) / prev_hi;
    }
    c[i] = y_prime[i];
    d[i] = y_array[i];
    prev_hi = hi;
    prev_si = si;
}
if (size > 1) {
    size_t last = size - 2;
    double hi = (x_array[last + 1] - x_array[last]);
    double si = (y_array[last + 1] - y_array[last]) / hi;
    a[last] = (y_prime[last] + y_prime[last + 1] - 2 * si) / hi / hi;
    b[last] = (3 * si - 2 * y_prime[last] - y_prime[last + 1]) / hi;
}
}
