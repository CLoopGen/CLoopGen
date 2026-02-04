#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
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

int control = 3;
int target = 7;
quantum_reg *reg;
int i;
_Complex float z = 0.70710678f + 0.70710678f * I;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of node data
    const int num_nodes = data_size / sizeof(quantum_reg_node);
    
    quantum_reg_node *nodes = (quantum_reg_node *)calloc(num_nodes, sizeof(quantum_reg_node));
    int *hash_table = (int *)malloc(num_nodes * sizeof(int));
    
    if (!nodes || !hash_table) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (int idx = 0; idx < num_nodes; idx++) {
        nodes[idx].amplitude = 1.0f + 0.0f * I;
        nodes[idx].state = (unsigned long long)idx;
        hash_table[idx] = idx % 1000;
    }
    
    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    if (!reg) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    reg->width = 32;
    reg->size = num_nodes;
    reg->hashw = 10;
    reg->node = nodes;
    reg->hash = hash_table;
}