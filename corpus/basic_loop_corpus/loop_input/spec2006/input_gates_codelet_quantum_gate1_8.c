#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

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

quantum_reg *reg;
int i;
int addsize;

void init_vars() {
    addsize = 134217728; // ~256MB of data: 134217728 elements * 16 bytes per node ≈ 2GB? Let's scale down.
    
    // Adjusting to fit within reasonable memory and time: aim for ~0.01 sec
    // On modern CPUs, simple stores can be done at high speed.
    // Let's target about 1 million iterations for ~0.01s estimate
    addsize = 1000000; // 1e6 iterations

    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->size = 0; // so that i + reg->size starts at i
    reg->width = 0;
    reg->hashw = 0;
    reg->hash = NULL;

    // Allocate node array with enough size: reg->size + addsize elements
    reg->node = (quantum_reg_node*)calloc(reg->size + addsize, sizeof(quantum_reg_node));
}

// Do not include main or extra headers beyond what's necessary