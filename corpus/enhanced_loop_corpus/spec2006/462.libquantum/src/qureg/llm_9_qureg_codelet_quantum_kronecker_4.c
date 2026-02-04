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
    int i, j_start;
    for (i = 0; i < reg1->size; i += 2) {
        for (j_start = 0; j_start < reg2->size; j_start += 2) {
            int i1 = i, i2 = i + 1;
            int j1 = j_start, j2 = j_start + 1;

            if (i2 < reg1->size) {
                if (j2 < reg2->size) {
                    // Unroll 2x2 block
                    reg.node[i1 * reg2->size + j1].state = (reg1->node[i1].state << reg2->width) | reg2->node[j1].state;
                    reg.node[i1 * reg2->size + j1].amplitude = reg1->node[i1].amplitude * reg2->node[j1].amplitude;

                    reg.node[i1 * reg2->size + j2].state = (reg1->node[i1].state << reg2->width) | reg2->node[j2].state;
                    reg.node[i1 * reg2->size + j2].amplitude = reg1->node[i1].amplitude * reg2->node[j2].amplitude;

                    reg.node[i2 * reg2->size + j1].state = (reg1->node[i2].state << reg2->width) | reg2->node[j1].state;
                    reg.node[i2 * reg2->size + j1].amplitude = reg1->node[i2].amplitude * reg2->node[j1].amplitude;

                    reg.node[i2 * reg2->size + j2].state = (reg1->node[i2].state << reg2->width) | reg2->node[j2].state;
                    reg.node[i2 * reg2->size + j2].amplitude = reg1->node[i2].amplitude * reg2->node[j2].amplitude;
                } else {
                    // Handle last column if odd size
                    reg.node[i1 * reg2->size + j1].state = (reg1->node[i1].state << reg2->width) | reg2->node[j1].state;
                    reg.node[i1 * reg2->size + j1].amplitude = reg1->node[i1].amplitude * reg2->node[j1].amplitude;

                    reg.node[i2 * reg2->size + j1].state = (reg1->node[i2].state << reg2->width) | reg2->node[j1].state;
                    reg.node[i2 * reg2->size + j1].amplitude = reg1->node[i2].amplitude * reg2->node[j1].amplitude;
                }
            } else {
                // Handle last row if odd size
                reg.node[i1 * reg2->size + j1].state = (reg1->node[i1].state << reg2->width) | reg2->node[j1].state;
                reg.node[i1 * reg2->size + j1].amplitude = reg1->node[i1].amplitude * reg2->node[j1].amplitude;
            }
        }
    }
}
