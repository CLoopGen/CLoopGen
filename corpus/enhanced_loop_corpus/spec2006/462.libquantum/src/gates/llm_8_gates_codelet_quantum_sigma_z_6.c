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
    int limit = reg->size;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            unsigned long long mask = (unsigned long long)1 << target;
            if (reg->node[i].state & mask)
                reg->node[i].amplitude *= -1;
            if (reg->node[i+1].state & mask)
                reg->node[i+1].amplitude *= -1;
        } else {
            if (reg->node[i].state & ((unsigned long long)1 << target))
                reg->node[i].amplitude *= -1;
        }
    }
}
