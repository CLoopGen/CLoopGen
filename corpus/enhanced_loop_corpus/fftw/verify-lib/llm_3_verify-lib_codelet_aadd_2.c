#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *c;
extern C *a;
extern C *b;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) {
        indices[j] = n - 1 - j; // reverse access pattern
    }
    for (i = 0; i < n; ++i) {
        int idx = indices[i];
        ((c[idx])[0]) = ((a[idx])[0]) + ((b[idx])[0]);
        ((c[idx])[1]) = ((a[idx])[1]) + ((b[idx])[1]);
    }
    free(indices);
}
