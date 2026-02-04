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
    for (int j = reg.size - 1; j >= 0; j--) {
        m.t[reg.node[j].state] = reg.node[j].amplitude + m.t[reg.node[j].state];
    }
}
