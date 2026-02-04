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
    // Variant 1: Increased computational intensity by unrolling the loop and reducing conditionals with bitwise optimizations.
    // Loop unrolled by a factor of 2 to reduce branching overhead and increase instruction-level parallelism.
    int size = reg->size;
    int remainder = size % 2;
    int limit = size - remainder;

    for (i = 0; i < limit; i += 2) {
        // Process two elements per iteration
        unsigned long long state1 = reg->node[i].state;
        unsigned long long state2 = reg->node[i+1].state;

        // Compute c1 and c2 for first element using bit extraction and XOR folding
        int c1_1 = !!(state1 & ((unsigned long long)1 << control1));
        c1_1 ^= !!(state1 & ((unsigned long long)1 << (control1 + width)));
        c1_1 ^= !!(state1 & ((unsigned long long)1 << (control1 + 2 * width)));

        int c2_1 = !!(state1 & ((unsigned long long)1 << control2));
        c2_1 ^= !!(state1 & ((unsigned long long)1 << (control2 + width)));
        c2_1 ^= !!(state1 & ((unsigned long long)1 << (control2 + 2 * width)));

        if (c1_1 == 1 && c2_1 == 1)
            reg->node[i].state ^= mask;

        // Compute c1 and c2 for second element
        int c1_2 = !!(state2 & ((unsigned long long)1 << control1));
        c1_2 ^= !!(state2 & ((unsigned long long)1 << (control1 + width)));
        c1_2 ^= !!(state2 & ((unsigned long long)1 << (control1 + 2 * width)));

        int c2_2 = !!(state2 & ((unsigned long long)1 << control2));
        c2_2 ^= !!(state2 & ((unsigned long long)1 << (control2 + width)));
        c2_2 ^= !!(state2 & ((unsigned long long)1 << (control2 + 2 * width)));

        if (c1_2 == 1 && c2_2 == 1)
            reg->node[i+1].state ^= mask;
    }

    // Handle leftover element
    if (remainder == 1) {
        i = limit;
        c1 = 0; c2 = 0;
        if (reg->node[i].state & ((unsigned long long)1 << control1)) c1 = 1;
        if (reg->node[i].state & ((unsigned long long)1 << (control1 + width))) c1 ^= 1;
        if (reg->node[i].state & ((unsigned long long)1 << (control1 + 2 * width))) c1 ^= 1;
        if (reg->node[i].state & ((unsigned long long)1 << control2)) c2 = 1;
        if (reg->node[i].state & ((unsigned long long)1 << (control2 + width))) c2 ^= 1;
        if (reg->node[i].state & ((unsigned long long)1 << (control2 + 2 * width))) c2 ^= 1;
        if (c1 == 1 && c2 == 1)
            reg->node[i].state ^= mask;
    }
}
