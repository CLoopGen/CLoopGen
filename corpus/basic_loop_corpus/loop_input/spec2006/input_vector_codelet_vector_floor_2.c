#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *vec;
int32 len;
float64 flr;
int32 i;

void init_vars() {
    len = 67108864; // ~256 MB of float32 data (67M elements)
    vec = (float32*)aligned_alloc(32, len * sizeof(float32));
    
    if (!vec) {
        exit(1);
    }

    flr = 0.5;
    i = 0;

    for (int32 j = 0; j < len; j++) {
        vec[j] = (float32)(drand48() * 1.0);
    }
}