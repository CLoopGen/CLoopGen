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

extern int control;
extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride of 2, then handle remainder
    int size = reg->size;
    int stride = 2;
    int i;

    // Strided access
    for (i = 0; i < size; i += stride) {
        if ((reg->node[i].state & ((unsigned long long)1 << control)))
            reg->node[i].state ^= ((unsigned long long)1 << target);
    }

    // Handle odd-sized arrays by checking the last element if missed
    if (size % stride != 0 && (size - 1) > 0) {
        i = size - 1;
        if ((reg->node[i].state & ((unsigned long long)1 << control)))
            reg->node[i].state ^= ((unsigned long long)1 << target);
    }
}
