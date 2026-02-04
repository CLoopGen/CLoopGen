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
    int step = 2;
    for (i = 0, j = 0; i < m->rows - 1; i += step) {
        if (m->t[i]) {
            reg.node[j].state = i;
            reg.node[j].amplitude = m->t[i];
            j++;
        }
        if (m->t[i + 1]) {
            reg.node[j].state = i + 1;
            reg.node[j].amplitude = m->t[i + 1];
            j++;
        }
    }
    if (i < m->rows && m->t[i]) {
        reg.node[j].state = i;
        reg.node[j].amplitude = m->t[i];
        j++;
    }
}
