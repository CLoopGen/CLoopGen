#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <time.h>

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

quantum_reg *reg;
int i;
_Complex float z;

void init_vars() {
    const int data_size_mb = 64;
    const int elements_per_mb = (1 << 20) / sizeof(quantum_reg_node);
    const int total_elements = data_size_mb * elements_per_mb;

    quantum_reg_node *nodes = calloc(total_elements, sizeof(quantum_reg_node));
    int *hash_table = calloc(total_elements, sizeof(int));

    for (int idx = 0; idx < total_elements; idx++) {
        nodes[idx].amplitude = 1.0f + 0.5f * idx;
        nodes[idx].state = idx;
        if (idx < total_elements)
            hash_table[idx] = -1;
    }

    reg = malloc(sizeof(quantum_reg));
    reg->width = 32;
    reg->size = total_elements;
    reg->hashw = 10;
    reg->node = nodes;
    reg->hash = hash_table;

    z = 0.99f + 0.01f * I;

    i = 0;
}