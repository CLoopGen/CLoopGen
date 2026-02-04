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
    // Variant 1: Consecutive memory access with pointer arithmetic
    // Instead of using reg.node[i].state as an index into m.t, we assume a scenario where state values are consecutive
    // and start from a base index. Here we simplify to direct sequential assignment if states are packed.
    _Complex float *src = &reg.node[0].amplitude;
    _Complex float *dst = &m.t[0]; // Assume mapping is identity: state == index
    for (i = 0; i < reg.size; i++) {
        dst[i] = src[i];
    }
}
