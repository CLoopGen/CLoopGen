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

extern int bits;
extern quantum_reg *reg;
extern int i;
extern unsigned long long l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *hash_indices = reg->hash;
    for (i = 0; i < reg->size; i++) {
        int index = hash_indices[i % reg->hashw];
        if (index >= 0 && index < reg->size) {
            l = reg->node[index].state << bits;
            reg->node[index].state = l;
        }
    }
}
