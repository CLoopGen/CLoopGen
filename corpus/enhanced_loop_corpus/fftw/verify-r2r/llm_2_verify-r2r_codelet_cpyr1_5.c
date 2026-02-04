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
    // Variant 1: Consecutive memory access with pointer arithmetic
    R *in_ptr = in;
    R *out_ptr = out;
    for (i = 0; i < n; ++i) {
        *out_ptr = *in_ptr * scale;
        in_ptr += is;
        out_ptr += os;
    }
}
