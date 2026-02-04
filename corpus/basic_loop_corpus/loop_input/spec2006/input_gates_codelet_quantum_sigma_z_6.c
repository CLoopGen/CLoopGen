#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
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

int target;
quantum_reg *reg;
int i;

void init_vars() {
    target = 3; 

    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->width = 20;
    reg->hashw = 1 << 10;
    reg->size = (1 << 20); 

    reg->node = (quantum_reg_node *)malloc(reg->size * sizeof(quantum_reg_node));
    reg->hash = (int *)malloc(reg->hashw * sizeof(int));

    for (int idx = 0; idx < reg->size; idx++) {
        reg->node[idx].amplitude = 1.0f + 0.0f * I;
        reg->node[idx].state = (unsigned long long)idx;
    }

    for (int idx = 0; idx < reg->hashw; idx++) {
        reg->hash[idx] = idx;
    }
}