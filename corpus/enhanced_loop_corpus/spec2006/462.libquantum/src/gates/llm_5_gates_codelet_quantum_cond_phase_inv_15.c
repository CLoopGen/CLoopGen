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
for (i = 0; i < reg->size; i++) {
    int control_bit = (reg->node[i].state & ((unsigned long long)1 << control)) != 0;
    int target_bit = (reg->node[i].state & ((unsigned long long)1 << target)) != 0;
    if (control_bit && target_bit) {
        reg->node[i].amplitude *= z;
    }
}
}
