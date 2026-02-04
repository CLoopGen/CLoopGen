#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
    float **hidden_weights;
    float **input_prev_weights;
    float **hidden_prev_weights;
} BPNN;

char *mem;
BPNN *new;
int n2;
int n3;
int i;
int j;
int memcnt;

static float **allocate_float_matrix(int rows, int cols) {
    float **matrix = (float **)calloc(rows, sizeof(float *));
    float *data = (float *)calloc(rows * cols, sizeof(float));
    for (int i = 0; i < rows; i++) {
        matrix[i] = &(data[i * cols]);
    }
    return matrix;
}

static void free_float_matrix(float **matrix) {
    if (matrix) {
        free(matrix[0]);
        free(matrix);
    }
}

void init_vars() {
    n2 = 100;
    n3 = 100;
    size_t total_data_size = (n2 + 1) * (n3 + 1) * sizeof(float);
    mem = (char *)calloc(total_data_size, 1);
    if (!mem) exit(1);

    new = (BPNN *)calloc(1, sizeof(BPNN));
    if (!new) exit(1);

    new->hidden_weights = allocate_float_matrix(n2 + 1, n3 + 1);
    memcnt = 0;

    for (int i = 0; i <= n2; i++) {
        for (int j = 0; j <= n3; j++) {
            memcpy(&mem[memcnt], &(new->hidden_weights[i][j]), sizeof(float));
            memcnt += sizeof(float);
        }
    }
    memcnt = 0;
}