#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

struct quantum_matrix_struct {
    int rows;
    int cols;
    _Complex float *t;
};

typedef struct quantum_matrix_struct quantum_matrix;

_Complex float *data_ptr;
quantum_matrix *m;
int i;
int size;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of complex float data
    const size_t num_elements = data_size / sizeof(_Complex float);

    data_ptr = aligned_alloc(32, data_size);
    if (!data_ptr) exit(1);

    for (size_t idx = 0; idx < num_elements; idx++) {
        data_ptr[idx] = (_Complex float)(idx % 7 == 0 ? 1.0f : 0.0f);
    }

    m = malloc(sizeof(quantum_matrix));
    if (!m) exit(1);

    m->rows = (int)num_elements;
    m->cols = 1;
    m->t = data_ptr;

    i = 0;
    size = 0;
}