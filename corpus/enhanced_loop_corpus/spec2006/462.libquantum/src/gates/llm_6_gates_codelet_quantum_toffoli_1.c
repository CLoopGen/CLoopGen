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
    _Complex float temp_amp;
    unsigned long long control_mask1 = (unsigned long long)1 << control1;
    unsigned long long control_mask2 = (unsigned long long)1 << control2;
    unsigned long long target_mask = (unsigned long long)1 << target;

    for (j = 0; j < reg->size; j++) {
        unsigned long long state = reg->node[j].state;
        if ((state & control_mask1) && (state & control_mask2)) {
            temp_amp = reg->node[j].amplitude; // Introduce RAW dependency: read before write
            reg->node[j].state = state ^ target_mask;
            reg->node[j].amplitude = temp_amp * 1.0f; // WAW-like dependency: rewrite same location
        }
    }
}
