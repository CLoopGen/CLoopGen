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
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int chunk_size = 4;
    int remainder = reg->size % chunk_size;
    for (i = 0; i < reg->size - remainder; i += chunk_size) {
        _Complex float temp[4];
        int valid[4];
        unsigned long long mask = (unsigned long long)1 << target;
        
        valid[0] = (reg->node[i + 0].state & mask) != 0;
        valid[1] = (reg->node[i + 1].state & mask) != 0;
        valid[2] = (reg->node[i + 2].state & mask) != 0;
        valid[3] = (reg->node[i + 3].state & mask) != 0;

        temp[0] = valid[0] ? z : (1.0f / z);
        temp[1] = valid[1] ? z : (1.0f / z);
        temp[2] = valid[2] ? z : (1.0f / z);
        temp[3] = valid[3] ? z : (1.0f / z);

        reg->node[i + 0].amplitude *= temp[0];
        reg->node[i + 1].amplitude *= temp[1];
        reg->node[i + 2].amplitude *= temp[2];
        reg->node[i + 3].amplitude *= temp[3];
    }
    for (; i < reg->size; i++) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= z;
        else
            reg->node[i].amplitude /= z;
    }
}
