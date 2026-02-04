#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern R *c;
extern R *a;
extern R *b;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to beginning
    for (i = n - 1; i >= 0; --i) {
        c[i] = a[i] - b[i];
    }
}
