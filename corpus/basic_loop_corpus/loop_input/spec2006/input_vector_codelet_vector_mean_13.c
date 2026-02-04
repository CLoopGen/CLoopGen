#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *mean;
int32 n_dim;
int32 i;
float64 f;

void init_vars() {
    n_dim = 1 << 20; // Approximately 4MB of float32 data (1M elements)
    mean = (float32*)calloc(n_dim, sizeof(float32));
    f = 2.5;
    i = 0;

    for (int j = 0; j < n_dim; j++) {
        mean[j] = 1.0f + j * 0.001f;
    }
}