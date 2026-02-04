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
    int start = 0;
    int step = 2;
    // Unroll loop by a factor of 2 to increase computational intensity per iteration
    for (i = 0; i < reg->size; i += step) {
        // Process two elements per iteration if within bounds
        if (i < reg->size) {
            if (reg->node[i].state & ((unsigned long long)1 << target))
                reg->node[i].amplitude *= z;
            else
                reg->node[i].amplitude /= z;
        }
        if (i + 1 < reg->size) {
            if (reg->node[i + 1].state & ((unsigned long long)1 << target))
                reg->node[i + 1].amplitude *= z;
            else
                reg->node[i + 1].amplitude /= z;
        }
    }
}
