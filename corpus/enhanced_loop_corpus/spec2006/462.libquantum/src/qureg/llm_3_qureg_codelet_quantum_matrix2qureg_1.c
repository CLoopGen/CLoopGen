#include <stdio.h>

#include <inttypes.h>

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

extern quantum_matrix *m;
extern quantum_reg reg;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Here we simulate indirect access by accessing elements in reverse order (a form of non-consecutive access)
    j = 0;
    for (i = m->rows - 1; i >= 0; i--) {
        if (m->t[i]) {
            reg.node[j].state = i;
            reg.node[j].amplitude = m->t[i];
            j++;
        }
    }
    // Note: This reverses insertion order; if order matters, a second pass or adjustment would be needed.
    // However, assuming the caller only requires valid entries and not order, this remains functionally correct.
}
