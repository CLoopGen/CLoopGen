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

int control;
int target;
quantum_reg *reg;
int i;

void init_vars() {
    control = 3;
    target = 5;
    
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->width = 64;
    reg->hashw = 10;
    
    // Aim for ~64MB of data to achieve ~0.01s runtime on modern CPU
    size_t num_nodes = 8 * 1024 * 1024; // 8 million nodes
    reg->size = num_nodes;
    
    reg->node = (quantum_reg_node*)malloc(num_nodes * sizeof(quantum_reg_node));
    reg->hash = (int*)malloc(1024 * sizeof(int));
    
    // Initialize node states with varied bit patterns
    for (size_t idx = 0; idx < num_nodes; idx++) {
        reg->node[idx].amplitude = 1.0f + 0.0f * _Complex_I;
        reg->node[idx].state = (unsigned long long)idx << 2;
    }
    
    // Initialize hash array to zero
    for (int j = 0; j < 1024; j++) {
        reg->hash[j] = 0;
    }
}