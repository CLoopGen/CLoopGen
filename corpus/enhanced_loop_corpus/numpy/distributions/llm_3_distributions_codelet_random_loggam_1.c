#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x2;
extern double gl0;
extern int64_t k;
extern double a[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse access but using pointer arithmetic for altered memory access pattern
    double *ptr = a + 9;  // Point to one past the last valid element (a[9])
    for (k = 8; k >= 0; k--) {
        ptr--;  // Move pointer back to current element a[k]
        gl0 *= x2;
        gl0 += *ptr;
    }
}
