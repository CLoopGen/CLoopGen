#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE 67108864  // 64 million elements ~ 256 MB for float (each 4 bytes)

float *initvalu;
float *initvalu_temp;
int i;

void init_vars() {
    initvalu = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));
    initvalu_temp = (float *)aligned_alloc(32, DATA_SIZE * sizeof(float));

    if (!initvalu || !initvalu_temp) {
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < DATA_SIZE; j++) {
        initvalu[j] = (float)(j % 1000) + 0.5f;
        initvalu_temp[j] = 0.0f;
    }
}