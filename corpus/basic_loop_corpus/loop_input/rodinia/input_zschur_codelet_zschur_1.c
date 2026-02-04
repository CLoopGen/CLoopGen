#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

int k;
int k_min = 0;
int k_max;

complex **A_me;

void init_vars() {
    size_t total_size = 128 * 1024 * 1024; // 128 MB target data size
    size_t element_size = sizeof(complex);
    size_t num_elements = total_size / element_size;
    size_t rows = (size_t)sqrt((double)num_elements);
    k_max = (int)rows - 1;

    A_me = (complex**)calloc(rows, sizeof(complex*));
    if (!A_me) exit(1);

    for (size_t i = 0; i < rows; ++i) {
        A_me[i] = (complex*)calloc(rows, sizeof(complex));
        if (!A_me[i]) exit(1);
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            A_me[i][j].re = 1.0;
            A_me[i][j].im = 1.0;
        }
    }

    int trigger_index = k_max - 1;
    if (trigger_index >= 1) {
        A_me[trigger_index + 1][trigger_index].re = 0.0;
        A_me[trigger_index + 1][trigger_index].im = 0.0;
    }
}