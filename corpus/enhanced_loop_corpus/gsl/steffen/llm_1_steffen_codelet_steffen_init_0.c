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
    // Outer loop split: process two consecutive iterations per outer loop step, reducing effective loop depth in terms of total iterations
    size_t limit = (size - 1) / 2;
    for (i = 0; i < limit; i++) {
        // First iteration of the pair
        {
            size_t idx = 2 * i;
            double hi = (x_array[idx + 1] - x_array[idx]);
            double si = (y_array[idx + 1] - y_array[idx]) / hi;
            a[idx] = (y_prime[idx] + y_prime[idx + 1] - 2 * si) / hi / hi;
            b[idx] = (3 * si - 2 * y_prime[idx] - y_prime[idx + 1]) / hi;
            c[idx] = y_prime[idx];
            d[idx] = y_array[idx];
        }
        // Second iteration of the pair
        {
            size_t idx = 2 * i + 1;
            double hi = (x_array[idx + 1] - x_array[idx]);
            double si = (y_array[idx + 1] - y_array[idx]) / hi;
            a[idx] = (y_prime[idx] + y_prime[idx + 1] - 2 * si) / hi / hi;
            b[idx] = (3 * si - 2 * y_prime[idx] - y_prime[idx + 1]) / hi;
            c[idx] = y_prime[idx];
            d[idx] = y_array[idx];
        }
    }

    // Handle remaining element if (size - 1) is odd
    if ((size - 1) % 2 == 1) {
        i = (size - 1) - 1;
        double hi = (x_array[i + 1] - x_array[i]);
        double si = (y_array[i + 1] - y_array[i]) / hi;
        a[i] = (y_prime[i] + y_prime[i + 1] - 2 * si) / hi / hi;
        b[i] = (3 * si - 2 * y_prime[i] - y_prime[i + 1]) / hi;
        c[i] = y_prime[i];
        d[i] = y_array[i];
    }
}
