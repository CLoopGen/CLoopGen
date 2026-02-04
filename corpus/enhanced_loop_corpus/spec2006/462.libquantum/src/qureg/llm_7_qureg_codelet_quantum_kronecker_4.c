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
    for (j = 0; j < reg2->size; j++) {
        _Complex float amp2 = reg2->node[j].amplitude;
        unsigned long long state2 = reg2->node[j].state;
        for (i = 0; i < reg1->size; i++) {
            int idx = i * reg2->size + j;
            reg.node[idx].state = (reg1->node[i].state << reg2->width) | state2;
            reg.node[idx].amplitude = reg1->node[i].amplitude * amp2;
        }
    }
}
