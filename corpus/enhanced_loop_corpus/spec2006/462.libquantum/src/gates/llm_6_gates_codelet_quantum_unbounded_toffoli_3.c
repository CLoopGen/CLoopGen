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
    int k;
    for (i = 0; i < reg->size; i++) {
        k = 0;
        for (j = 0; j < controlling; j++) {
            if (reg->node[i].state & ((unsigned long long)1 << controls[j])) {
                k++;
            } else {
                break;
            }
        }
        if (k == controlling)
            reg->node[i].state ^= ((unsigned long long)1 << target);
    }
}
