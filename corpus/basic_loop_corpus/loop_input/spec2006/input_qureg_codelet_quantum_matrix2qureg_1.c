#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

struct quantum_matrix_struct {
    int rows;
    int cols;
    _Complex float *t;
};

typedef struct quantum_matrix_struct quantum_matrix;

struct quantum_reg_node_struct {
    _Complex float amplitude;
    unsigned long long state;
};

typedef struct quantum_reg_node_struct quantum_reg_node;

struct quantum_reg_struct {
    int width;
    int size;
    int hashw;
    quantum_reg_node *node;
    int *hash;
};

typedef struct quantum_reg_struct quantum_reg;

quantum_matrix *m;
quantum_reg reg;
int i;
int j;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~256 MB of complex float data

    m = (quantum_matrix *)malloc(sizeof(quantum_matrix));
    m->rows = data_size / sizeof(_Complex float);
    m->cols = 1;
    m->t = (_Complex float *)calloc(m->rows, sizeof(_Complex float));

    for (int idx = 0; idx < m->rows; idx += 7) {
        m->t[idx] = 1.0f + 0.5f * idx;
    }

    reg.width = 64;
    reg.size = m->rows;
    reg.hashw = 1024;
    reg.node = (quantum_reg_node *)malloc(reg.size * sizeof(quantum_reg_node));
    reg.hash = (int *)calloc(reg.hashw, sizeof(int));

    i = 0;
    j = 0;
}