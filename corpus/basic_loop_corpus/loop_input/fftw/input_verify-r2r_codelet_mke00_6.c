#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *a = NULL;
int n;
int c;
int i;

void init_vars() {
    n = 1 << 20;  // 1M elements, ~16MB for complex doubles (2 doubles per element)
    c = 1;        // valid index in [0,1] for bench_complex
    a = (C*)aligned_alloc(32, n * sizeof(C));
    
    if (!a) exit(1);
    
    // Initialize all data to zero
    for (int j = 0; j < n; ++j) {
        a[j][0] = 0.0;
        a[j][1] = 0.0;
    }
}