#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern int n;
extern R *in;
extern int is;
extern R *out;
extern int os;
extern R scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride-2 access and fused operations
    // Only processes every second element, reducing memory traffic and increasing arithmetic per accessed data
    for (i = 0; i < n; i += 2) {
        out[i * os] = (in[i * is] + in[(i+1) * is]) * scale * 0.5;  // Averages two inputs and scales
    }
}
