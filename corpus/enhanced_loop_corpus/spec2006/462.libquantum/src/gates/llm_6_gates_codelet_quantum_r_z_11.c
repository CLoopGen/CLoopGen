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
    _Complex float z_conj = 1.0f / z;
    for (i = 0; i < reg->size; i++) {
        unsigned long long mask = (unsigned long long)1 << target;
        int condition = (reg->node[i].state & mask) != 0;
        _Complex float factor = condition ? z : z_conj;
        reg->node[i].amplitude *= factor;
    }
}
