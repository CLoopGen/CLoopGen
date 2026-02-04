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
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < reg->size; i += stride) {
        if (i + 1 < reg->size) {
            // Process two elements per iteration with a fixed stride
            if (reg->node[i].state & ((unsigned long long)1 << control)) {
                if (reg->node[i].state & ((unsigned long long)1 << target))
                    reg->node[i].amplitude *= z;
            }
            if (reg->node[i + 1].state & ((unsigned long long)1 << control)) {
                if (reg->node[i + 1].state & ((unsigned long long)1 << target))
                    reg->node[i + 1].amplitude *= z;
            }
        } else {
            // Handle last element if size is odd
            if (reg->node[i].state & ((unsigned long long)1 << control)) {
                if (reg->node[i].state & ((unsigned long long)1 << target))
                    reg->node[i].amplitude *= z;
            }
        }
    }
}
