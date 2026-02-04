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

extern quantum_reg *reg;
extern int i;
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int size = reg->size;
    for (i = 0; i < size; i += 2) {
        reg->node[i].amplitude *= z;
    }
    // Handle odd-sized arrays by processing last element if needed
    if (size % 2 == 1) {
        reg->node[size - 1].amplitude *= z;
    }
}
