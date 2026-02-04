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
    len = 64 * 1024 * 1024 / sizeof(float32);  // ~256 MB of float32 data
    val = (float32*)calloc(len, sizeof(float32));
    if (!val) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int32 idx = 0; idx < len; idx++) {
        val[idx] = (float32)(rand() % 10000) / 10.0f;
    }

    bi = 0;
    i = 0;
}