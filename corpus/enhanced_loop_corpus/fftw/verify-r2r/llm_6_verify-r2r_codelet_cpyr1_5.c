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
    R temp = scale;
    for (i = 0; i < n; ++i) {
        out[i * os] = in[i * is] * temp;
        temp = out[i * os]; // Introduce WAW and RAW dependency: temp depends on previous out write
    }
}
