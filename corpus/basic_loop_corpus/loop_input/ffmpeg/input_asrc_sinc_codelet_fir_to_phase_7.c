#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (1 << 20)  // Approximately 4MB of float data (~1M elements)

static float *static_h_data;
static float *static_work_data;

float **h = &static_h_data;
int *len;
float phase;
float *work;
int i;
int work_len;
int begin;

void init_vars() {
    static_h_data = (float*)calloc(DATA_SIZE, sizeof(float));
    static_work_data = (float*)calloc(DATA_SIZE, sizeof(float));
    
    h = &static_h_data;
    len = (int*)malloc(sizeof(int));
    *len = DATA_SIZE / 2;  // Ensure *len <= DATA_SIZE
    phase = 55.0f;  // > 50.F to trigger the reverse indexing path
    work = static_work_data;
    work_len = DATA_SIZE;
    begin = 1000;

    // Ensure all array accesses in loop are within bounds:
    // index = (begin + (phase > 50.F ? *len - 1 - i : i) + work_len) & (work_len - 1)
    // Since work_len is power of two, mask is valid. Max offset: begin + *len - 1 + work_len
    // With current values, max logical index ~ begin + *len - 1 + work_len
    // After masking with (work_len-1), stays within [0, work_len-1]
}