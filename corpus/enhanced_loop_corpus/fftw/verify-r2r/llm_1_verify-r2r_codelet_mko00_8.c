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
    for (i = 1; i + i < n; ++i) {
        a[n - i][c] = -a[i][c];
        if (i + 2 < n) {
            a[n - (i + 1)][c] = -a[i + 1][c];
        }
    }
}
