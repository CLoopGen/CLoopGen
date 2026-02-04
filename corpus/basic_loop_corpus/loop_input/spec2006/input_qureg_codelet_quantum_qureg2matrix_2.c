#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

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

struct quantum_matrix_struct {
    int rows;
    int cols;
    _Complex float *t;
};

typedef struct quantum_matrix_struct quantum_matrix;

extern quantum_reg reg;
extern quantum_matrix m;
extern int i;

quantum_reg reg;
quantum_matrix m;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of data for sufficient runtime (~0.01 sec on modern CPU)
    const int num_elements = data_size / sizeof(_Complex float);

    reg.width = 32;
    reg.size = num_elements;
    reg.hashw = 8;

    reg.node = (quantum_reg_node*)aligned_alloc(32, num_elements * sizeof(quantum_reg_node));
    reg.hash = (int*)aligned_alloc(32, (1 << reg.hashw) * sizeof(int));

    m.rows = num_elements;
    m.cols = 1;
    m.t = (_Complex float*)aligned_alloc(32, num_elements * sizeof(_Complex float));

    for (int idx = 0; idx < num_elements; idx++) {
        reg.node[idx].amplitude = idx + 0.5f + I * (idx * 0.25f);
        reg.node[idx].state = idx % num_elements; // ensure state is within bounds of m.t
    }

    for (int idx = 0; idx < num_elements; idx++) {
        m.t[idx] = 0.0f + I * 0.0f;
    }

    for (int idx = 0; idx < (1 << reg.hashw); idx++) {
        reg.hash[idx] = -1;
    }
}