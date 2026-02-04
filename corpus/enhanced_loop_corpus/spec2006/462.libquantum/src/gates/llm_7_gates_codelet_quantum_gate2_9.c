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

extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    volatile int prev_index = 0;
    for (i = 0; i < (1 << reg->hashw); i++) {
        int current_index = (prev_index + i) & ((1 << reg->hashw) - 1); // Introduce RAW dependency: current_index depends on prev_index
        reg->hash[current_index] = 0;
        prev_index = current_index; // Loop-carried dependency via prev_index (RAW/WAR)
    }
}
