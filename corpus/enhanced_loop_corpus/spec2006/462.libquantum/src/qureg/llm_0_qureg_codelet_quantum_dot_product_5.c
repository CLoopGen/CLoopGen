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

extern quantum_reg *reg2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < reg2->hashw; j++) {
        for (i = (1 << j); i < (1 << (j + 1)) && i < (1 << reg2->hashw); i++)
            reg2->hash[i] = 0;
    }
    if (reg2->hashw == 0)
        for (i = 0; i < (1 << reg2->hashw); i++)
            reg2->hash[i] = 0;
}
