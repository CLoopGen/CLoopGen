#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef float float32;
typedef int int32;

float32 *mean;
int32 n_dim;
int32 i;

void init_vars() {
    n_dim = 67108864; // ~256 MB of float32 data (67108864 elements * 4 bytes)
    mean = (float32*)calloc(n_dim, sizeof(float32));
    if (!mean) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}