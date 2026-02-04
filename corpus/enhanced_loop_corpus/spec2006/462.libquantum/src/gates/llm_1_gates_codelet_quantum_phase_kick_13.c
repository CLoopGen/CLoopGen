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
    if (reg->size > 0) {
        i = 0;
        for (int block = 0; block < reg->size; block += 1) {
            if (reg->node[i].state & ((unsigned long long)1 << target))
                reg->node[i].amplitude *= z;
            i++;
        }
    }
}
