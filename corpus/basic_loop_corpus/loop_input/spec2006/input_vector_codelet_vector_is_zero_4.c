#include <stdlib.h>
#include <stdint.h>

typedef float float32;
typedef int int32;

float32 *vec;
int32 len;
int32 i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(float32); // ~256 MB of float32 data
    vec = (float32*)aligned_alloc(32, len * sizeof(float32));
    for (int32 j = 0; j < len; j++) {
        vec[j] = 0.0f;
    }
    // Ensure loop terminates by setting last element to non-zero if len > 0
    if (len > 0) {
        vec[len - 1] = 1.0f;
    }
    i = 0;
}