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
    int local_i;
    _Complex float temp_amplitude;
    unsigned long long temp_state;
    for (local_i = 0; local_i < reg->size; local_i++) {
        temp_state = reg->node[local_i].state;
        if (temp_state & ((unsigned long long)1 << target)) {
            temp_amplitude = reg->node[local_i].amplitude * -1;
            reg->node[local_i].amplitude = temp_amplitude;
        }
    }
}
