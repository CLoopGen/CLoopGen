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

extern int control1;
extern int control2;
extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < reg->size; i += 2) {
    if (i + 1 < reg->size) {
        unsigned long long mask_control1 = (unsigned long long)1 << control1;
        unsigned long long mask_control2 = (unsigned long long)1 << control2;
        unsigned long long mask_target = (unsigned long long)1 << target;

        _Complex float temp1 = reg->node[i].amplitude;
        _Complex float temp2 = reg->node[i+1].amplitude;

        unsigned long long state1 = reg->node[i].state;
        unsigned long long state2 = reg->node[i+1].state;

        if (state1 & mask_control1 && state1 & mask_control2) {
            reg->node[i].state = state1 ^ mask_target;
        }
        if (state2 & mask_control1 && state2 & mask_control2) {
            reg->node[i+1].state = state2 ^ mask_target;
        }

        reg->node[i].amplitude = temp1 * temp1; 
        reg->node[i+1].amplitude = temp2 * temp2;
    } else {
        unsigned long long mask_control1 = (unsigned long long)1 << control1;
        unsigned long long mask_control2 = (unsigned long long)1 << control2;
        unsigned long long mask_target = (unsigned long long)1 << target;

        if (reg->node[i].state & mask_control1 && reg->node[i].state & mask_control2) {
            reg->node[i].state ^= mask_target;
        }
        reg->node[i].amplitude *= reg->node[i].amplitude;
    }
}
}
