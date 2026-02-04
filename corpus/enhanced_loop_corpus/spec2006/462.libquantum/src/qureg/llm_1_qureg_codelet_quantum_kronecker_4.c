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



void loop(){
    int total_size = reg1->size * reg2->size;
    for (int idx = 0; idx < total_size; idx++) {
        i = idx / reg2->size;
        j = idx % reg2->size;
        reg.node[idx].state = ((reg1->node[i].state) << reg2->width) | reg2->node[j].state;
        reg.node[idx].amplitude = reg1->node[i].amplitude * reg2->node[j].amplitude;
    }
}
