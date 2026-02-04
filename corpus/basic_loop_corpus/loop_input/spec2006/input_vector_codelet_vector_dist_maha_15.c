#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *vec;
float32 *mean;
float32 *varinv;
int32 len;
float64 dist;
float64 diff;
int32 i;

void init_vars() {
    len = 67108864;  // ~256MB: 3 arrays of float32 (12 bytes per element) -> 67M elements ≈ 256MB total

    vec = (float32*)calloc(len, sizeof(float32));
    mean = (float32*)calloc(len, sizeof(float32));
    varinv = (float32*)calloc(len, sizeof(float32));

    srand(time(NULL));
    for (int32 j = 0; j < len; j++) {
        vec[j] = (float32)(rand() % 1000) / 100.0f;
        mean[j] = (float32)(rand() % 1000) / 100.0f;
        varinv[j] = (float32)(rand() % 1000) / 100.0f + 1.0f;  // Avoid zero
    }

    dist = 1e10;
    diff = 0.0;
    i = 0;
}