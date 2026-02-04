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
    quantum_reg_node *nodes = reg->node;
    int *ctrl = controls;
    unsigned long long mask;
    for (i = 0; i < reg->size; i++) {
        for (j = 0; j < controlling; j++) {
            mask = (unsigned long long)1 << ctrl[j];
            if (!(nodes[i].state & mask))
                goto next_iteration;
        }
        nodes[i].state ^= ((unsigned long long)1 << target);
        next_iteration: ;
    }
}
