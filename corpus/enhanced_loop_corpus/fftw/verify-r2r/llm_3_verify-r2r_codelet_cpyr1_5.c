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
    // Variant 2: Strided access with reversed iteration order (backward traversal)
    for (i = n - 1; i >= 0; --i) {
        out[i * os] = in[i * is] * scale;
    }
}
