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

extern int width;
extern int control1;
extern int control2;
extern quantum_reg *reg;
extern int i;
extern int c1;
extern int c2;
extern unsigned long long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < reg->size; i++) {
        int c1 = ((reg->node[i].state >> control1) & 1) ^
                 ((reg->node[i].state >> (control1 + width)) & 1) ^
                 ((reg->node[i].state >> (control1 + 2 * width)) & 1);
        int c2 = ((reg->node[i].state >> control2) & 1) ^
                 ((reg->node[i].state >> (control2 + width)) & 1) ^
                 ((reg->node[i].state >> (control2 + 2 * width)) & 1);
        if (c1 == 1 && c2 == 1) {
            reg->node[i].state ^= mask;
        }
    }
}
