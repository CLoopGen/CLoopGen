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
    // Variant 1: Strided memory access (access every 2nd element in reverse order, wrapping logic to maintain recurrence)
    double temp_f = f;
    for (i = 2; i <= n; i += 2) {
        if (i + 1 <= n) {
            temp_f = temp_f * a + qcoeff[i + 1];  // Simulate strided access: process i+1 instead of i
        }
        temp_f = temp_f * a + qcoeff[i];
    }
    f = temp_f;
}
