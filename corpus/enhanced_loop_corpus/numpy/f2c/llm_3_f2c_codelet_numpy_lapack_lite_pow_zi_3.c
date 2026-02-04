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
    // Variant 2: Memory Access Pattern Modification using indirect access via lookup table
    // We simulate indirect access by precomputing bit-check indices in an array and iterating through them
    integer indices[64]; // assume max bits in u
    integer count = 0;
    unsigned long temp = n;
    
    // Build indirect access pattern: record positions where bits are set or shifted
    while (temp) {
        indices[count++] = temp & 1;
        temp >>= 1;
    }

    // Traverse the indirect index list instead of direct bit manipulation
    for (integer i = 0; i < count; ++i) {
        if (indices[i]) {
            t = q.r * x.r - q.i * x.i;
            q.i = q.r * x.i + q.i * x.r;
            q.r = t;
        }

        // Reconstruct current u from remaining bits for squaring logic
        unsigned long remaining = n >> (i + 1);
        if (remaining) {
            t = x.r * x.r - x.i * x.i;
            x.i = 2 * x.r * x.i;
            x.r = t;
        } else {
            break;
        }
    }
}
