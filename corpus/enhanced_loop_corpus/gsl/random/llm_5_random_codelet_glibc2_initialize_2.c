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
for (i = 1; i < n && n > 0; i++) {
    const long h = s / 127773;
    long t = 16807 * (s - h * 127773) - h * 2836;
    if (t >= 0) goto positive_branch;
    s = t + 2147483647;
    goto store_result;
positive_branch:
    s = t;
store_result:
    x[i] = s;
}
}
