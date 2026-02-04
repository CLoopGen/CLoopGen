#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double y;
extern double *a;
extern double *b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (reverse order) memory access from high to low index
    // Ensures data is accessed sequentially but in reverse, potentially improving cache behavior
    for (k = n; k >= 1; --k) {
        double fac = (n - k + 1.) / (k * y);
        a[k] = 0.5 * fac * a[k - 1];
        b[k] = fac * b[k - 1];
    }
}
