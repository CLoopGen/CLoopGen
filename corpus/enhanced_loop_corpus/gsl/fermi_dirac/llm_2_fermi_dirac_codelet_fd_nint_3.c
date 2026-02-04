#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern double a;
extern double f;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (i = n - 1; i >= 1; i -= 2) {
        f = f * a + qcoeff[i];
    }
    // Handle remaining element if n is even
    if ((n - 1) % 2 == 0 && n >= 2) {
        f = f * a + qcoeff[1];
    }
}
