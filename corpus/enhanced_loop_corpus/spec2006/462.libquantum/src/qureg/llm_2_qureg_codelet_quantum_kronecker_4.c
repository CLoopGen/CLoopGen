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

extern quantum_reg *reg1;
extern quantum_reg *reg2;
extern int i;
extern int j;
extern quantum_reg reg;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (consecutive i, then j), we access with a fixed stride on the output array
    // Here, we reverse the loop order to create a strided access pattern on reg.node
    int total_size = reg2->size;
    for (j = 0; j < reg2->size; j++) {
        for (i = 0; i < reg1->size; i++) {
            int index = i * total_size + j;
            reg.node[index].state = ((reg1->node[i].state) << reg2->width) | reg2->node[j].state;
            reg.node[index].amplitude = reg1->node[i].amplitude * reg2->node[j].amplitude;
        }
    }
}
