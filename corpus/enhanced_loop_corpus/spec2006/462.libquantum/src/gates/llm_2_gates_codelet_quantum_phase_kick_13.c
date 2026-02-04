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
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential access, traverse the array with a stride of 2, then handle remainder
    int stride = 2;
    int limit = reg->size - (reg->size % stride);
    
    for (i = 0; i < limit; i += stride) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= z;
    }
    // Handle remaining elements
    for (i = limit; i < reg->size; i++) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= z;
    }
}
