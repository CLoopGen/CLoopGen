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
    int k;
    unsigned long long mask = (unsigned long long)1 << target;
    _Complex float factor;
    for (k = 0; k < reg->size; k++) {
        if (reg->node[k].state & mask) {
            reg->node[k].amplitude *= -(__extension__ 1.Fi);
            reg->node[k].state ^= mask;
        } else {
            reg->node[k].amplitude *= (__extension__ 1.Fi);
            reg->node[k].state ^= mask;
        }
    }
}
