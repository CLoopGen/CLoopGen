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
    int stride = 2;
    for (i = 0; i < reg->size; i += stride) {
        l = reg->node[i].state << bits;
        reg->node[i].state = l;
        if (i + 1 < reg->size) {
            l = reg->node[i + 1].state << bits;
            reg->node[i + 1].state = l;
        }
    }
}
