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
    const long h = s / 127773;
    const long t = 16807 * (s - h * 127773) - h * 2836;
    s = (t < 0) ? (t + 2147483647) : t;
    x[i] = s;
}
}
