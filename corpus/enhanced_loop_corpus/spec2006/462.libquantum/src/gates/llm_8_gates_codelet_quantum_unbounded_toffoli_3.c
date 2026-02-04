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
    for (i = 0; i < reg->size; i += 2) {
        if (i + 1 < reg->size) {
            for (j = 0; j < controlling; j++) {
                unsigned long long mask = (unsigned long long)1 << controls[j];
                if (!(reg->node[i].state & mask) || !(reg->node[i+1].state & mask)) {
                    break;
                }
            }
            if (j == controlling) {
                unsigned long long target_mask = (unsigned long long)1 << target;
                reg->node[i].state ^= target_mask;
                reg->node[i+1].state ^= target_mask;
            }
        } else {
            for (j = 0; j < controlling && (reg->node[i].state & ((unsigned long long)1 << controls[j])); j++)
                ;
            if (j == controlling)
                reg->node[i].state ^= ((unsigned long long)1 << target);
        }
    }
}
