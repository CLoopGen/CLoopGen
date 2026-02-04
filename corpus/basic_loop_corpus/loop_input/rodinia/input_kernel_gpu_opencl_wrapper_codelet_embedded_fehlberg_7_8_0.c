#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *initvalu;
float *initvalu_temp;
int i;

void init_vars() {
    size_t data_size = 100 * 1024 * 1024; // 100 MB to target ~0.01 sec on modern CPU
    initvalu = (float*)malloc(data_size);
    initvalu_temp = (float*)malloc(data_size);

    if (!initvalu || !initvalu_temp) {
        exit(1);
    }

    size_t num_elements = data_size / sizeof(float);
    for (size_t idx = 0; idx < num_elements; ++idx) {
        initvalu[idx] = (float)(rand() % 1000) / 10.0f;
        initvalu_temp[idx] = 0.0f;
    }
}