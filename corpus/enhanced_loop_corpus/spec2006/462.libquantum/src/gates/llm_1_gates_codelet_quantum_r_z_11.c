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
    int outer = reg->size > 0 ? 1 : 0;
    for (i = 0; i < outer; i++) {
        int j;
        for (j = 0; j < reg->size; j++) {
            if (reg->node[j].state & ((unsigned long long)1 << target))
                reg->node[j].amplitude *= z;
            else
                reg->node[j].amplitude /= z;
        }
    }
}
