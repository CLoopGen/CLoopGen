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
    // Variant 1: Consecutive memory access with loop unrolling for stride-1 access pattern
    // We assume reg->size is divisible by 2 for simplicity in unrolling
    int limit = reg->size - (reg->size % 2);
    for (i = 0; i < limit; i += 2) {
        for (int j = 0; j < 2; j++) {
            int idx = i + j;
            c1 = 0;
            c2 = 0;
            unsigned long long state = reg->node[idx].state;

            if (state & ((unsigned long long)1 << control1))
                c1 = 1;
            if (state & ((unsigned long long)1 << (control1 + width)))
                c1 ^= 1;
            if (state & ((unsigned long long)1 << (control1 + 2 * width)))
                c1 ^= 1;

            if (state & ((unsigned long long)1 << control2))
                c2 = 1;
            if (state & ((unsigned long long)1 << (control2 + width)))
                c2 ^= 1;
            if (state & ((unsigned long long)1 << (control2 + 2 * width)))
                c2 ^= 1;

            if (c1 == 1 && c2 == 1)
                reg->node[idx].state ^= mask;
        }
    }
    // Handle remainder
    for (; i < reg->size; i++) {
        c1 = 0;
        c2 = 0;
        unsigned long long state = reg->node[i].state;

        if (state & ((unsigned long long)1 << control1))
            c1 = 1;
        if (state & ((unsigned long long)1 << (control1 + width)))
            c1 ^= 1;
        if (state & ((unsigned long long)1 << (control1 + 2 * width)))
            c1 ^= 1;

        if (state & ((unsigned long long)1 << control2))
            c2 = 1;
        if (state & ((unsigned long long)1 << (control2 + width)))
            c2 ^= 1;
        if (state & ((unsigned long long)1 << (control2 + 2 * width)))
            c2 ^= 1;

        if (c1 == 1 && c2 == 1)
            reg->node[i].state ^= mask;
    }
}
