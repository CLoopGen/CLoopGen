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
    for (i = 0; i < n; ++i) {
        if ((i & 7) != 0) { // Skip every 8th element processing (simulated striding control)
            c[i] = a[i] - b[i];
        } else {
            c[i] = 0.0; // Alternate behavior on aligned indices
        }
    }
}
