#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

float h = 0.001f;

float *initvalu;
float b13_1 = 1.0f;
float b13_4 = 0.5f;
float b13_5 = 0.25f;
float b13_6 = 0.125f;
float b13_7 = 0.0625f;
float b13_8 = 0.03125f;
float b13_9 = 0.015625f;
float b13_10 = 0.0078125f;
float *initvalu_temp;
float **finavalu_temp;
int i;

const int M = 12;
const int N_val = 91;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // Aim for ~64MB of data
    const int num_rows = M;
    const int num_cols = N_val;

    size_t row_size = num_cols * sizeof(float);
    size_t data_size = num_rows * row_size;

    // Allocate large block for all row data
    float *data_block = (float*)calloc(data_size, 1);
    if (!data_block) exit(1);

    // Allocate array of row pointers
    finavalu_temp = (float**)malloc(num_rows * sizeof(float*));
    if (!finavalu_temp) exit(1);

    // Point each row to its segment in the data block
    for (int r = 0; r < num_rows; r++) {
        finavalu_temp[r] = &data_block[r * num_cols];
    }

    // Allocate and initialize initvalu and initvalu_temp
    initvalu = (float*)malloc(num_cols * sizeof(float));
    if (!initvalu) exit(1);
    for (int c = 0; c < num_cols; c++) {
        initvalu[c] = (float)(c + 1);
    }

    initvalu_temp = (float*)malloc(num_cols * sizeof(float));
    if (!initvalu_temp) exit(1);
    memset(initvalu_temp, 0, num_cols * sizeof(float));

    // Initialize finavalu_temp data with non-zero values for computation
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            finavalu_temp[r][c] = (float)(r * num_cols + c + 1);
        }
    }
}