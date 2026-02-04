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
    int j;
    _Complex float local_accum[8] = {0}; // Local accumulation to create artificial WAW and WAR dependencies
    for (i = 0, j = 0; i < reg->size; i++) {
        if (reg->node[i].state & ((unsigned long long)1 << control)) {
            if (reg->node[i].state & ((unsigned long long)1 << target)) {
                local_accum[j % 8] = reg->node[i].amplitude * z; // WAR: Write after read via reuse of index
                reg->node[i].amplitude = local_accum[(j-1) % 8]; // WAW: Write after write with prior slot
                j++;
            }
        }
    }
    // Final dummy write to ensure all locals are used (prevent optimization)
    if (j > 0)
        reg->node[0].amplitude = local_accum[0];
}
