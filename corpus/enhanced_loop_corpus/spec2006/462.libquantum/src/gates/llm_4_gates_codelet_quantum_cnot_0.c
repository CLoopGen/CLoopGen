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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < reg->size; i++) {
    if (!((reg->node[i].state & ((unsigned long long)1 << control))))
        continue;
    reg->node[i].state ^= ((unsigned long long)1 << target);
}
}
