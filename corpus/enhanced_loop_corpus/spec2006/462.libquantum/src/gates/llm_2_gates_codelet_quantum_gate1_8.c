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

extern quantum_reg *reg;
extern int i;
extern int addsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < addsize; i += stride) {
        reg->node[i + reg->size].state = 0;
        reg->node[i + reg->size].amplitude = 0;
        if (i + 1 < addsize) {
            reg->node[i + 1 + reg->size].state = 0;
            reg->node[i + 1 + reg->size].amplitude = 0;
        }
    }
}
