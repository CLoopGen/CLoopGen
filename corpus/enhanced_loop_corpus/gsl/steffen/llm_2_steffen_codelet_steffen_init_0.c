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
    // Variant 1: Strided Memory Access (stride of 2, unrolled by 2 with safety check)
    size_t limit = (size - 1) / 2 * 2;  // Make it even for safe unrolling
    for (i = 0; i < limit; i += 2) {
        // First iteration of the unrolled pair
        double hi0 = (x_array[i + 1] - x_array[i]);
        double si0 = (y_array[i + 1] - y_array[i]) / hi0;
        a[i] = (y_prime[i] + y_prime[i + 1] - 2 * si0) / hi0 / hi0;
        b[i] = (3 * si0 - 2 * y_prime[i] - y_prime[i + 1]) / hi0;
        c[i] = y_prime[i];
        d[i] = y_array[i];

        // Second iteration of the unrolled pair
        double hi1 = (x_array[i + 2] - x_array[i + 1]);
        double si1 = (y_array[i + 2] - y_array[i + 1]) / hi1;
        a[i + 1] = (y_prime[i + 1] + y_prime[i + 2] - 2 * si1) / hi1 / hi1;
        b[i + 1] = (3 * si1 - 2 * y_prime[i + 1] - y_prime[i + 2]) / hi1;
        c[i + 1] = y_prime[i + 1];
        d[i + 1] = y_array[i + 1];
    }
    // Handle remaining element if size is odd
    if ((size - 1) % 2 == 1) {
        i = size - 2;
        double hi = (x_array[i + 1] - x_array[i]);
        double si = (y_array[i + 1] - y_array[i]) / hi;
        a[i] = (y_prime[i] + y_prime[i + 1] - 2 * si) / hi / hi;
        b[i] = (3 * si - 2 * y_prime[i] - y_prime[i + 1]) / hi;
        c[i] = y_prime[i];
        d[i] = y_array[i];
    }
}
