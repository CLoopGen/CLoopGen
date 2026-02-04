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

extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop by processing two elements per iteration
    int size = reg->size;
    int remainder = size % 2;
    
    // Process pairs of elements with stride-like access (i and i+1)
    for (i = 0; i < size - remainder; i += 2) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= -1;
        if (reg->node[i + 1].state & ((unsigned long long)1 << target))
            reg->node[i + 1].amplitude *= -1;
    }
    
    // Handle leftover element if size is odd
    if (remainder && i < size) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= -1;
    }
}
