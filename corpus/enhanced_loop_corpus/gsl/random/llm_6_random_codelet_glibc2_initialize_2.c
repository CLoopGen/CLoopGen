#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) {
    const long h_prev = (i > 1) ? s / 127773 : 1;
    const long t = 16807 * (s - h_prev * 127773) - h_prev * 2836;
    long temp_s = (t < 0) ? t + 2147483647 : t;
    x[i] = temp_s;
    if (i % 2 == 0) {
        s = temp_s; // Update s only on even indices, breaking uniform loop-carried dependency
    }
}
}
