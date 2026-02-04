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
    _Complex float local_z = z * z;
    for (i = 0; i < reg->size; i++) {
        unsigned long long mask_control = (unsigned long long)1 << control;
        unsigned long long mask_target = (unsigned long long)1 << target;
        unsigned long long state = reg->node[i].state;
        if ((state & mask_control) && (state & mask_target)) {
            reg->node[i].amplitude *= local_z;
            reg->node[i].amplitude -= (_Complex float)0.1f;
        }
    }
}
