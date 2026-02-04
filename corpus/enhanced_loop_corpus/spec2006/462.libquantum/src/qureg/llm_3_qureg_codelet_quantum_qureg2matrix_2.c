#include <stdio.h>

#include <inttypes.h>

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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Access elements in a strided pattern: write every 2nd element, simulating alignment or decimation
    // This assumes that valid state indices are even, or we're downsampling the register nodes.
    int stride = 2;
    int n = reg.size;
    for (i = 0; i < n; i += stride) {
        unsigned long long target_index = reg.node[i].state % m.cols; // Ensure within bounds
        m.t[target_index] = reg.node[i].amplitude;
    }
    // Handle remainder if needed, still without while
    if (n > 0 && (n - 1) % stride != 0) {
        for (i = n - (n - 1) % stride - 1; i < n; i++) {
            if (i % stride != 0) {
                unsigned long long target_index = reg.node[i].state % m.cols;
                m.t[target_index] = reg.node[i].amplitude;
            }
        }
    }
}
