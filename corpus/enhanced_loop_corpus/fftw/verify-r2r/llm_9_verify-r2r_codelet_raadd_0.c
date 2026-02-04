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
    // Variant 2: Reduced effective trip count with stride-2 access, decreasing memory touches but maintaining same output size via zero-fill fallback
    int i;
    for (i = 0; i < n; i += 2) {
        c[i] = a[i] + b[i];
        if (i + 1 < n) {
            c[i+1] = 0.0; // Simulate reduced computation by setting alternate elements to fixed value
        }
    }
}
