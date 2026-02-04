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
    for (i = 0; i < reg1->size; i++) {
        if (reg1->node[i].amplitude == 0.0f) continue;
        for (j = 0; j < reg2->size; j++) {
            if (reg2->node[j].amplitude == 0.0f) continue;
            reg.node[i * reg2->size + j].state = ((reg1->node[i].state) << reg2->width) | reg2->node[j].state;
            reg.node[i * reg2->size + j].amplitude = reg1->node[i].amplitude * reg2->node[j].amplitude;
        }
    }
}
