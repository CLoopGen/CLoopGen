#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
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

int controlling = 3;
quantum_reg *reg;
int target = 5;
int *controls;
int i;
int j;

void init_vars() {
    // Allocate and initialize controls array
    controls = (int*)malloc(controlling * sizeof(int));
    controls[0] = 2;
    controls[1] = 4;
    controls[2] = 6;

    // Set target to a valid qubit index
    target = 7;

    // Allocate reg structure
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));

    // Configure register parameters
    reg->width = 8;
    reg->hashw = 10;

    // Set size to achieve desired data volume (~64MB of node data)
    // Each node is sizeof(quantum_reg_node) = 16 bytes (assuming alignment)
    // Aim for ~16M nodes -> ~256MB total data
    reg->size = 16 * 1024 * 1024;  // 16 million nodes

    // Allocate node array
    reg->node = (quantum_reg_node*)malloc(reg->size * sizeof(quantum_reg_node));
    if (!reg->node) {
        exit(1);
    }

    // Initialize nodes with non-zero states for meaningful bitwise operations
    for (int idx = 0; idx < reg->size; idx++) {
        reg->node[idx].amplitude = 1.0f + 0.0f * _Complex_I;
        reg->node[idx].state = (unsigned long long)idx << 3;  // Spread out states
    }

    // Allocate hash table (not used in loop, but allocate to be safe)
    reg->hash = (int*)malloc((1 << reg->hashw) * sizeof(int));
    if (!reg->hash) {
        exit(1);
    }
    for (int idx = 0; idx < (1 << reg->hashw); idx++) {
        reg->hash[idx] = idx % reg->size;
    }
}