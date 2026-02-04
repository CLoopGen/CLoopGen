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
extern int addsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < addsize; i++) {
        reg->node[i + reg->size].state = i; // Introduce loop-carried dependency: each iteration writes a value used in next iteration
        reg->node[i + reg->size].amplitude = reg->node[i + reg->size - 1].state; // RAW dependency: read state written in previous iteration
    }
}
