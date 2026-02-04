#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define MEMORY_SIZE 10
#define DATA_SIZE (1 << 20) * 64  // ~256MB of float data (64M elements)

float *output;
float *input;
float *coef;
float *memory;
int length;
float sum;
int i;
int j;

void init_vars() {
    length = DATA_SIZE;
    
    input = (float*)aligned_alloc(32, length * sizeof(float));
    output = (float*)aligned_alloc(32, length * sizeof(float));
    coef = (float*)aligned_alloc(32, MEMORY_SIZE * sizeof(float));
    memory = (float*)aligned_alloc(32, MEMORY_SIZE * sizeof(float));
    
    if (!input || !output || !coef || !memory) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (int idx = 0; idx < length; idx++) {
        input[idx] = (float)(idx % 1000) / 100.0f;
        output[idx] = 0.0f;
    }
    
    for (int idx = 0; idx < MEMORY_SIZE; idx++) {
        coef[idx] = (float)(idx + 1) / MEMORY_SIZE;
        memory[idx] = 0.0f;
    }
    
    sum = 0.0f;
    i = 0;
    j = 0;
}