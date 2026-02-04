#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct {
    int input_n;
    int hidden_n;
    int output_n;
    float *input_units;
    float *hidden_units;
    float *output_units;
    float *hidden_delta;
    float *output_delta;
    float *target;
    float **input_weights;
    float **hidden_prev_weights;
    float **hidden_weights;
    float **input_prev_weights;
} BPNN;

char *mem;
BPNN *new;
int n1 = 499;
int n2 = 511;
int i, j;
int memcnt = 0;

void init_vars() {
    const size_t total_data_size = 1 << 20; // ~1MB of data to process
    const size_t float_count = total_data_size / sizeof(float);
    
    // Adjust n1 and n2 so that (n1+1)*(n2+1) ≈ float_count
    n1 = 499;
    n2 = 511;
    
    mem = (char*)calloc(total_data_size, 1);
    if (!mem) exit(1);

    new = (BPNN*)calloc(1, sizeof(BPNN));
    if (!new) exit(1);

    new->input_n = n1 + 1;
    new->hidden_n = n2 + 1;

    new->input_weights = (float**)calloc(n1 + 1, sizeof(float*));
    if (!new->input_weights) exit(1);

    for (i = 0; i <= n1; i++) {
        new->input_weights[i] = (float*)calloc(n2 + 1, sizeof(float));
        if (!new->input_weights[i]) exit(1);
    }

    memcnt = 0;
}