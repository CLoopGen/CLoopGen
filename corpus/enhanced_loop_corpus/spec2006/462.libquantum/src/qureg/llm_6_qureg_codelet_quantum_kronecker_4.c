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
    int k;
    for (i = 0; i < reg1->size; i++) {
        _Complex float amp1 = reg1->node[i].amplitude;
        unsigned long long state1 = reg1->node[i].state << reg2->width;
        for (j = 0, k = i * reg2->size; j < reg2->size; j++, k++) {
            reg.node[k].state = state1 | reg2->node[j].state;
            reg.node[k].amplitude = amp1 * reg2->node[j].amplitude;
        }
    }
}
