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
long prev_s = s;
for (i = 1; i < n; i++) {
    const long h = prev_s / 127773;
    const long t = 16807 * (prev_s - h * 127773) - h * 2836;
    const long current_s = (t < 0) ? t + 2147483647 : t;
    x[i] = current_s;
    prev_s = current_s; // Use local variable to remove direct loop-carried dependency on global 's'
}
s = prev_s; // Update global 's' only once after loop
}
