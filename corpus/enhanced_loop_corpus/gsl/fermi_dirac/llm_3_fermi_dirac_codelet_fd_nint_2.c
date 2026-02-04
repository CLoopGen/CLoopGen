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
    // Variant 2: Consecutive forward access with temporary array-like traversal using offset indexing
    double acc = f;
    int idx;
    for (idx = 2; idx <= n; idx++) {
        acc = acc * a + qcoeff[idx];  // Maintain logical equivalence but emphasize consecutive access pattern
    }
    f = acc;
}
