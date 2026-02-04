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
    int j;
    _Complex float local_z = z;
    for (i = 0, j = reg->size - 1; i < reg->size; i++, j--) {
        if (i <= j) {
            if (reg->node[i].state & ((unsigned long long)1 << target))
                reg->node[i].amplitude *= local_z;
            if (i != j && (reg->node[j].state & ((unsigned long long)1 << target)))
                reg->node[j].amplitude *= local_z;
        }
    }
}
