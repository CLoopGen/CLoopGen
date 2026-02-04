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

extern int controlling;
extern quantum_reg *reg;
extern int target;
extern int *controls;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    int full_mask_computed = 0;
    unsigned long long combined_control_mask = 0;

    if (!full_mask_computed && controlling > 0) {
        for (j = 0; j < controlling; j++) {
            combined_control_mask |= (unsigned long long)1 << controls[j];
        }
        full_mask_computed = 1;
    }

    for (i = 0; i < reg->size; i++) {
        unsigned long long state = reg->node[i].state;
        int matches = 1;
        for (j = 0; j < controlling; j++) {
            if (!(state & ((unsigned long long)1 << controls[j]))) {
                matches = 0;
                break;
            }
        }
        if (matches)
            reg->node[i].state ^= ((unsigned long long)1 << target);
    }
}
