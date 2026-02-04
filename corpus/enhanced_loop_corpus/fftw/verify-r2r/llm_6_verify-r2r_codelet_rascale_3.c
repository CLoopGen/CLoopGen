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
    R temp = alpha;
    for (i = 0; i < n; ++i) {
        a[i] *= temp;
        temp = a[i]; // Introduce RAW and WAW dependency: each iteration depends on previous write to temp
    }
}
