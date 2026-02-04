#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *a;
extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 2; i + i < n; i += 2) {
        bench_real re = a[i][0];
        bench_real im = a[i][1];
        a[n - i][0] = -(re * 1.5 + im * 0.5);
        a[n - i][1] = -(im * 1.5 - re * 0.5);
    }
}
