#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

extern int nb_codes;
extern Node *nodes;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    int i_even, i_odd;
    sum = 0; // Reset sum as per original intent

    // Process even indices with stride 2
    for (i_even = 0; i_even < nb_codes; i_even += 2) {
        nodes[i_even].sym = i_even;
        nodes[i_even].n0 = -2;
        sum += nodes[i_even].count;
    }

    // Process odd indices with stride 2
    for (i_odd = 1; i_odd < nb_codes; i_odd += 2) {
        nodes[i_odd].sym = i_odd;
        nodes[i_odd].n0 = -2;
        sum += nodes[i_odd].count;
    }
}
