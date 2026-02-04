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

int target;
quantum_reg *reg;
int i;
_Complex float z;

void init_vars() {
    target = 3;
    z = 1.0f + 0.5f * I;

    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->width = 20;
    reg->size = 1 << 18; // 262144 elements, roughly 2MB data
    reg->hashw = 10;

    reg->node = (quantum_reg_node *)calloc(reg->size, sizeof(quantum_reg_node));
    reg->hash = (int *)calloc(1 << reg->hashw, sizeof(int));

    for (int i = 0; i < reg->size; i++) {
        reg->node[i].amplitude = (float)(i % 100) / 100.0f + (float)(i % 79) / 100.0f * I;
        reg->node[i].state = (unsigned long long)i;
    }
}