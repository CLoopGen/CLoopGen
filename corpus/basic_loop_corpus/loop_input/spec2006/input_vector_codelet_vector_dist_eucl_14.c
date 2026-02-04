#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *v1;
float32 *v2;
int32 len;
float64 d;
int32 i;

void init_vars() {
    len = 8000000; // Approximately 30.5 MB of data (8e6 * 4 * 2), tuned for ~0.01s runtime
    
    v1 = (float32*)aligned_alloc(32, len * sizeof(float32));
    v2 = (float32*)aligned_alloc(32, len * sizeof(float32));
    
    for (int32 j = 0; j < len; j++) {
        v1[j] = (float32)(j % 1000) + 1.5f;
        v2[j] = (float32)((j + 500) % 1000) + 0.8f;
    }
    
    d = 0.0;
    i = 0;
}