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
for (i = 0; i < reg->size; i++) {
    l = reg->node[i].state << bits;
    reg->node[i].state = l;
}

}
