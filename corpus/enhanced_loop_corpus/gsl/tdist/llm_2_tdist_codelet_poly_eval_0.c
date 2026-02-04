#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern unsigned int n;
extern double x;
extern unsigned int i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (i = 1; i < n; i += 2) {
        y = x * (y + c[i]);
    }
    // Handle the last element if n is even and was skipped
    if (n % 2 == 0 && i - 1 == n - 2) {
        y = x * (y + c[n-1]);
    }
}
