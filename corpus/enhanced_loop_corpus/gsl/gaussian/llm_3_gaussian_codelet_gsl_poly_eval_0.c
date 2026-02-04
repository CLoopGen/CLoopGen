#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access in reverse but using an offset pointer to simulate different access pattern
    double * restrict c_ptr = &c[len - 1];
    ans = c[len - 1]; // initialize with last element
    for (i = len - 2; i >= 0; i--) {
        ans = c_ptr[-(len - 1 - i) + 1] + x * ans; // effectively c[i] via pointer arithmetic
    }
}
