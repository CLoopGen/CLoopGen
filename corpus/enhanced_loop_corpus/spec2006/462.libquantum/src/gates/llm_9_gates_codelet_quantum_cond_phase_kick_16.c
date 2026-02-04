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
        unsigned long long state = reg->node[i].state;
        unsigned long long control_mask = (unsigned long long)1 << control;
        unsigned long long target_mask = (unsigned long long)1 << target;
        if ((state & control_mask) && (state & target_mask)) {
            reg->node[i].amplitude *= local_z;
            reg->node[i].amplitude -= z; // Additional arithmetic to increase intensity
        }
    }
}
