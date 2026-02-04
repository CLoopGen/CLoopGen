#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE 67108864  // 64 million elements ~ 256 MB for two float arrays

float *initvalu;
float *initvalu_temp;
int i;

void init_vars() {
    initvalu = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));
    initvalu_temp = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));

    if (!initvalu || !initvalu_temp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < DATA_SIZE; i++) {
        initvalu[i] = (float)(i % 1000) + 0.5f;
        initvalu_temp[i] = 0.0f;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

__attribute__((destructor))
static void destructor_free() {
    free(initvalu);
    free(initvalu_temp);
}