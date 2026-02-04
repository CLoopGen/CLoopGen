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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via bit-reversed order)
    // This changes access pattern to non-consecutive, bit-reversed indexing
    int size = reg->size;
    for (i = 0; i < size; i++) {
        // Compute bit-reversed index up to necessary bit width
        int reversed_i = 0;
        int temp = i;
        int width = reg->width; // assuming width gives us bit width for reversal
        for (int b = 0; b < width; b++) {
            reversed_i = (reversed_i << 1) | (temp & 1);
            temp >>= 1;
        }
        // Clamp reversed index within valid range
        if (reversed_i < size) {
            if (reg->node[reversed_i].state & ((unsigned long long)1 << target))
                reg->node[reversed_i].amplitude *= -1;
        }
    }
}
