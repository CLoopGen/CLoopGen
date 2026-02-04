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
    R acc = 0.0;
    for (i = 0; i < n; ++i) {
        acc += in[i * is]; // Accumulate input values — introduces loop-carried RAW dependency
        out[i * os] = acc * scale; // Each output depends on accumulated state
    }
    out[(n - 1) * os] = acc * scale; // Redundant write to enforce WAW dependency if n >= 1
}
