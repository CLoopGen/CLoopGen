#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *a;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 4) {
        ((a[i])[0]) = ((a[i])[1]) = 0.;
        if (i + 2 < n) {
            ((a[i+1])[0]) = ((a[i+1])[1]) = 0.;
            ((a[i+2])[0]) = ((a[i+2])[1]) = 0.;
            ((a[i+3])[0]) = ((a[i+3])[1]) = 0.;
        }
    }
}
