#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer n;
extern unsigned long u;
extern double t;
extern doublecomplex q;
extern doublecomplex x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern
    // Simulate strided memory traversal by unrolling the effect over iterations
    // Although no explicit array is given, we reinterpret scalar updates as if operating on a sequence with stride
    integer stride = 2; // conceptual stride
    for (u = n; u > 0; ) {
        if (u & 1) {
            t = q.r * x.r - q.i * x.i;
            q.i = q.r * x.i + q.i * x.r;
            q.r = t;
        }
        u >>= 1;
        if (u == 0) break;

        // Stride simulation: repeat operation once per stride step (conceptual)
        for (integer s = 0; s < stride && u > 0; ++s) {
            t = x.r * x.r - x.i * x.i;
            x.i = 2 * x.r * x.i;
            x.r = t;
            u >>= 1;
            if (u == 0) break;
        }
    }
}
