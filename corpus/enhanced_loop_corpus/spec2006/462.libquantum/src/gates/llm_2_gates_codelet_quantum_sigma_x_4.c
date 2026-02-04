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
    int stride = 2;
    for (i = 0; i < reg->size; i += stride) {
        reg->node[i].state ^= ((unsigned long long)1 << target);
        if (i + 1 < reg->size) {
            reg->node[i + 1].state ^= ((unsigned long long)1 << target);
        }
    }
}
