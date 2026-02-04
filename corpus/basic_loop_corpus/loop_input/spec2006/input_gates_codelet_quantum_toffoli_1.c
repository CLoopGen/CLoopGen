#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h>
#include <stdint.h>

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

int control1;
int control2;
int target;
quantum_reg *reg;
int i;

void init_vars() {
    // Set control and target qubit indices
    control1 = 3;
    control2 = 5;
    target = 7;

    // Allocate and initialize reg
    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->width = 64;
    reg->hashw = 10;

    // Aim for ~100ms runtime: use around 1M elements as typical modern CPUs
    // can process this in tens to hundreds of microseconds depending on cache.
    // Adjusting to hit ~0.01s: use ~250K-500K range.
    reg->size = 400000;  // ~400k elements

    // Allocate node array
    reg->node = (quantum_reg_node *)calloc(reg->size, sizeof(quantum_reg_node));

    // Initialize node states with diverse bit patterns to ensure realistic branching
    for (int idx = 0; idx < reg->size; idx++) {
        // Use pseudo-random but deterministic state
        unsigned long long state = ((unsigned long long)idx * 1103515245ULL + 12345ULL) & 0xFFFFFFFFFULL;
        reg->node[idx].state = state;
        reg->node[idx].amplitude = idx + 1.0f + 0.1f * idx * _Complex_I;
    }

    // Allocate and initialize hash (not used in loop, but required to avoid null dereference)
    reg->hash = (int *)calloc(1 << reg->hashw, sizeof(int));
    for (int idx = 0; idx < (1 << reg->hashw); idx++) {
        reg->hash[idx] = -1;
    }
}