#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern R *a;
extern R alpha;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a[i] *= alpha;
        } else {
            a[i] *= alpha * 1.1;
        }
    }
}
