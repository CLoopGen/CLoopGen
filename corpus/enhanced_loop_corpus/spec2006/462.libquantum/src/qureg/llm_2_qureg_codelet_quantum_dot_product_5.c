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
    int shift = reg2->hashw;
    int size = 1 << shift;
    for (int i = 0; i < size; i += 2) {
        reg2->hash[i] = 0;
        if (i + 1 < size) {
            reg2->hash[i + 1] = 0;
        }
    }
}
