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

_Complex float z = 1.0f + 0.5f * _Complex_I;
int target = 3;

quantum_reg *reg;

int i;

void init_vars() {
    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->width = 20;
    reg->hashw = 10;
    
    // Aim for ~64MB of node data: each node is 16 bytes (amplitude: 8, state: 8)
    // So 64MB / 16 = 4M nodes
    reg->size = 4 * 1024 * 1024;  // 4 million elements
    
    reg->node = (quantum_reg_node *)calloc(reg->size, sizeof(quantum_reg_node));
    reg->hash = (int *)calloc((1 << reg->hashw), sizeof(int));
    
    // Initialize amplitudes and states
    for (i = 0; i < reg->size; i++) {
        reg->node[i].amplitude = (1.0f + 0.1f * i) + (0.1f * (i % 10)) * _Complex_I;
        reg->node[i].state = (unsigned long long)i * 7 + 12345ULL;
    }
    
    // Initialize hash table if needed (not used in loop but allocated to avoid NULL deref)
    for (i = 0; i < (1 << reg->hashw); i++) {
        reg->hash[i] = -1;
    }
}