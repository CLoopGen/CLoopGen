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

extern int control1;
extern int control2;
extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride of 2, then handle remainder
    int size = reg->size;
    int stride = 2;

    // First pass: strided access
    for (i = 0; i < size; i += stride) {
        if (reg->node[i].state & ((unsigned long long)1 << control1)) {
            if (reg->node[i].state & ((unsigned long long)1 << control2)) {
                reg->node[i].state ^= ((unsigned long long)1 << target);
            }
        }
    }

    // Second pass: handle odd-indexed elements if stride=2 and size is odd
    for (i = 1; i < size; i += stride) {
        if (reg->node[i].state & ((unsigned long long)1 << control1)) {
            if (reg->node[i].state & ((unsigned long long)1 << control2)) {
                reg->node[i].state ^= ((unsigned long long)1 << target);
            }
        }
    }
}
