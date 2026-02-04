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

extern int control1;
extern int control2;
extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < reg->size; depth1++) {
    for (i = depth1; i < reg->size && i == depth1; i++) {
        if (reg->node[i].state & ((unsigned long long)1 << control1)) {
            if (reg->node[i].state & ((unsigned long long)1 << control2)) {
                reg->node[i].state ^= ((unsigned long long)1 << target);
            }
        }
    }
}
}
