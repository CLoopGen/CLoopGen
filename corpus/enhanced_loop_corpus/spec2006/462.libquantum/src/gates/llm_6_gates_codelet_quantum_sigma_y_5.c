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

extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    _Complex float temp_amp;
    unsigned long long temp_state;
    for (j = 0; j < reg->size; j++) {
        temp_state = reg->node[j].state ^ ((unsigned long long)1 << target);
        temp_amp = reg->node[j].amplitude;
        if (temp_state & ((unsigned long long)1 << target))
            temp_amp *= (__extension__ 1.Fi);
        else
            temp_amp *= -(__extension__ 1.Fi);
        reg->node[j].state = temp_state;
        reg->node[j].amplitude = temp_amp;
    }
}
