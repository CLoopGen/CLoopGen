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

extern int target;
extern quantum_reg *reg;
extern int i;
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via virtual duplication
    // Each original element is processed twice with lightweight condition, increasing memory accesses
    // but reducing arithmetic per iteration relative to work.
    int extended_size = reg->size * 2;
    for (i = 0; i < extended_size; i++) {
        int idx = i % reg->size;
        // Lighter-weight check with redundant access pattern
        if ((reg->node[idx].state >> target) & 1ULL) {
            reg->node[idx].amplitude *= z;
        }
    }
}
