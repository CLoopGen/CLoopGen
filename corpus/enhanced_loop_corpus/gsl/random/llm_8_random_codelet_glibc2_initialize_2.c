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
for (i = 1; i < n; i += 2) {
    const long h1 = s / 127773;
    const long t1 = 16807 * (s - h1 * 127773) - h1 * 2836;
    long s1 = (t1 < 0) ? t1 + 2147483647 : t1;
    x[i] = s1;

    if (i + 1 < n) {
        const long h2 = s1 / 127773;
        const long t2 = 16807 * (s1 - h2 * 127773) - h2 * 2836;
        s = (t2 < 0) ? t2 + 2147483647 : t2;
        x[i + 1] = s;
    } else {
        s = s1;
    }
}
}
