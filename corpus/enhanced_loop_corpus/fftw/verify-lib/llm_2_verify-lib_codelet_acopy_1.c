#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *c;
extern C *a;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            ((c[i])[0]) = ((a[i])[0]);
            ((c[i])[1]) = ((a[i])[1]);
            ((c[i+1])[0]) = ((a[i+1])[0]);
            ((c[i+1])[1]) = ((a[i+1])[1]);
        } else {
            ((c[i])[0]) = ((a[i])[0]);
            ((c[i])[1]) = ((a[i])[1]);
        }
    }
}
