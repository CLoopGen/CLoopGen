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

int target = 3;  // arbitrary valid bit position for XOR operation
quantum_reg *reg;
int i;

void init_vars() {
    // Aim for approximately 100 million iterations to last ~0.01s on modern CPUs
    int size = 100000000;
    
    // Allocate and initialize reg
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->width = 64;
    reg->size = size;
    reg->hashw = 16;
    
    // Allocate node array
    reg->node = (quantum_reg_node*)calloc(size, sizeof(quantum_reg_node));
    if (!reg->node) {
        exit(1);
    }
    
    // Initialize node states with non-zero values for observable effect
    for (int j = 0; j < size; j++) {
        reg->node[j].amplitude = 1.0f + 0.5f * j;
        reg->node[j].state = (unsigned long long)j;
    }
    
    // Allocate and initialize hash (not used in loop but part of struct)
    reg->hash = (int*)calloc(1 << reg->hashw, sizeof(int));
    if (!reg->hash) {
        exit(1);
    }
}