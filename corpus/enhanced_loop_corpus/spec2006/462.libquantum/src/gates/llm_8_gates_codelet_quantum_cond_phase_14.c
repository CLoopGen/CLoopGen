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
    int limit = reg->size;
    for (i = 0; i < limit; i += 2) {
        unsigned long long state1 = reg->node[i].state;
        if (state1 & ((unsigned long long)1 << control)) {
            if (state1 & ((unsigned long long)1 << target))
                reg->node[i].amplitude *= z;
        }
        if (i + 1 < limit) {
            unsigned long long state2 = reg->node[i+1].state;
            if (state2 & ((unsigned long long)1 << control)) {
                if (state2 & ((unsigned long long)1 << target))
                    reg->node[i+1].amplitude *= z;
            }
        }
    }
}
