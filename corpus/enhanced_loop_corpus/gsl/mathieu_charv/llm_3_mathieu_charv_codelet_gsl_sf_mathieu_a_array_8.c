#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int even_order;
extern unsigned int ii;
extern double *tt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Fixed Offset Pattern
    // Restructure memory access to write all elements of a given field first (structure of arrays style).
    // First pass: set every third element starting at index 3 to qq
    // Second pass: set values at indices 3*ii+1 to 4*ii*ii
    // Third pass: set every third element starting at index 5 to qq (since 3*(ii)+2 = 3*ii+2)
    // All accesses are now strided with step 3, improving predictability.

    // Fill tt[3*ii] = qq
    for (ii = 1; ii < even_order - 1; ii++) {
        tt[3 * ii] = qq;
    }

    // Fill tt[3*ii + 1] = 4*ii*ii
    for (ii = 1; ii < even_order - 1; ii++) {
        tt[3 * ii + 1] = 4 * ii * ii;
    }

    // Fill tt[3*ii + 2] = qq
    for (ii = 1; ii < even_order - 1; ii++) {
        tt[3 * ii + 2] = qq;
    }
}
