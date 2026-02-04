#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n <= 1) return;
// Outer loop controlling granularity; simulates reduced effective depth via splitting
int chunk = (n - 1 + 1) / 1; // Single logical iteration, same as original
int start = 1;
int end = n;

for (i = start; i < end; i++) {
    x[i] = 1103515145 * x[i - 1] + 12345;
}
}
