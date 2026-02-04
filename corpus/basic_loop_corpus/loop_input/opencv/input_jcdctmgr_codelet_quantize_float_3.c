#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short JCOEF;
typedef JCOEF *JCOEFPTR;

float *divisors;
float *workspace;
float temp;
int i;
JCOEFPTR output_ptr;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(float)) // ~64MB of floats

static float divisors_storage[DATA_SIZE];
static float workspace_storage[DATA_SIZE];
static short output_storage[DATA_SIZE];

void init_vars() {
    divisors = divisors_storage;
    workspace = workspace_storage;
    output_ptr = output_storage;

    for (int j = 0; j < DATA_SIZE; j++) {
        divisors[j] = 1.0f + (j % 100) * 0.01f;
        workspace[j] = (j % 2 == 0) ? 100.5f : -99.5f;
    }
}