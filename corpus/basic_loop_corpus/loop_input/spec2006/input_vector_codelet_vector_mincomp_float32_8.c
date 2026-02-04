#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *val;
int32 len;
int32 i;
int32 bi;

void init_vars() {
    len = 67108864;  // Approximately 256 MB of float32 data (67M elements)
    val = (float32*)malloc(len * sizeof(float32));
    if (!val) {
        exit(1);
    }

    // Initialize with random values to ensure meaningful comparisons
    srand(time(NULL));
    for (int32 idx = 0; idx < len; idx++) {
        val[idx] = (float32)(rand()) / RAND_MAX * 1000.0f;
    }

    // Initialize loop control variables
    i = 1;
    bi = 0;  // Must be within [0, len-1]; safe starting point
}