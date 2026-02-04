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

int target;
quantum_reg *reg;
int i;

void init_vars() {
    // Set target to a reasonable qubit index (e.g., 5)
    target = 5;

    // Allocate reg structure
    reg = (quantum_reg*)calloc(1, sizeof(quantum_reg));
    
    // Determine size to achieve ~0.01s runtime
    // Assume modern CPU does ~1e9 ops/sec, so 10M iterations ≈ 0.01s
    // Use 8 million elements as a balance between accuracy and portability
    reg->size = 8000000;
    reg->width = 20;
    reg->hashw = 16;

    // Allocate node array
    reg->node = (quantum_reg_node*)calloc(reg->size, sizeof(quantum_reg_node));
    
    // Allocate and initialize hash (not used in loop but part of struct)
    reg->hash = (int*)calloc(1 << reg->hashw, sizeof(int));

    // Initialize node data to avoid NaN or undefined behavior
    for (int j = 0; j < reg->size; j++) {
        reg->node[j].amplitude = 1.0f + 0.0f * _Complex_I;
        reg->node[j].state = j; // Ensure spread of states
    }

    // Initialize global loop index
    i = 0;
}