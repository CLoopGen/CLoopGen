#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *vec;
int32 len;
float64 sum;
int32 i;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    len = target_bytes / sizeof(float32);
    vec = (float32*)aligned_alloc(32, len * sizeof(float32));
    
    if (!vec) {
        len = 0;
        sum = 0.0;
        return;
    }

    for (int32 j = 0; j < len; j++) {
        vec[j] = (float32)(j % 1000) + 1.0f;
    }

    sum = 0.0;
    i = 0;
}