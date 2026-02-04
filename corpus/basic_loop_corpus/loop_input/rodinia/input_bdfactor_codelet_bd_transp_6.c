#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i = 512;
int j;
int jj;
int lb = 100;
int ub = 100;
int n1 = 1024;

double **in_v;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // Aim for ~16MB of data
    size_t rows = 1024;
    size_t row_size_bytes = total_data_size / rows;
    size_t doubles_per_row = row_size_bytes / sizeof(double);
    
    in_v = (double**)calloc(rows, sizeof(double*));
    if (!in_v) exit(1);

    for (size_t r = 0; r < rows; r++) {
        in_v[r] = (double*)calloc(doubles_per_row, sizeof(double));
        if (!in_v[r]) exit(1);
        for (size_t c = 0; c < doubles_per_row; c++) {
            in_v[r][c] = (double)(rand() % 1000) / 10.0;
        }
    }

    i = 512;
    n1 = doubles_per_row - 1;
    lb = 100;
    ub = 100;
}