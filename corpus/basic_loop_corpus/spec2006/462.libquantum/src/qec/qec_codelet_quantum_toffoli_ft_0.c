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
for (i = 0; i < reg->size; i++) {
    c1 = 0;
    c2 = 0;
    if (reg->node[i].state & ((unsigned long long)1 << control1))
        c1 = 1;
    if (reg->node[i].state & ((unsigned long long)1 << (control1 + width))) {
        c1 ^= 1;
    }
    if (reg->node[i].state & ((unsigned long long)1 << (control1 + 2 * width))) {
        c1 ^= 1;
    }
    if (reg->node[i].state & ((unsigned long long)1 << control2))
        c2 = 1;
    if (reg->node[i].state & ((unsigned long long)1 << (control2 + width))) {
        c2 ^= 1;
    }
    if (reg->node[i].state & ((unsigned long long)1 << (control2 + 2 * width))) {
        c2 ^= 1;
    }
    if (c1 == 1 && c2 == 1)
        reg->node[i].state = reg->node[i].state ^ mask;
}

}
