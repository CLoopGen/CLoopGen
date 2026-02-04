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



void loop(){
    int k = 0;
    for (i = 0; i < m->rows; i++) {
        _Complex float val = m->t[i];
        if (val) {
            reg.node[k].state = i;
            reg.node[k].amplitude = val;
            k++;
        }
    }
    j = k;
}
