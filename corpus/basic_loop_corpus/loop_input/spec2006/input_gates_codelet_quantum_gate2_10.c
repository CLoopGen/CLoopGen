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

quantum_reg *reg;
int i;
int addsize;

void init_vars() {
    addsize = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->width = 32;
    reg->size = 1 << 19; // Ensure i + reg->size + addsize doesn't overflow allocated memory
    reg->hashw = 10;
    
    // Allocate enough node space: reg->size + addsize
    reg->node = (quantum_reg_node*)calloc(reg->size + addsize, sizeof(quantum_reg_node));
    reg->hash = (int*)calloc(1 << reg->hashw, sizeof(int));
}

// External symbols defined:
// - reg: points to a heap-allocated quantum_reg with sufficient node buffer
// - i: loop index, initialized in loop
// - addsize: set to 1M for appropriate workload
// All initializations ensure no out-of-bounds access in the loop