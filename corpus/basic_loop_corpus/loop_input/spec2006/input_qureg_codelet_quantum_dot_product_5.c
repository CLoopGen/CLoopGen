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

quantum_reg *reg2;
int i;

void init_vars() {
    reg2 = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg2->width = 0;
    reg2->size = 0;
    
    // Set hashw so that 1 << hashw is about 2^24 (~16.7M elements) to target ~0.01s runtime
    // This corresponds to roughly 64 MB of data (each int is 4 bytes)
    reg2->hashw = 24;
    
    size_t hash_size = (size_t)1 << reg2->hashw; // 2^24 = ~16.7M
    
    reg2->hash = (int*)calloc(hash_size, sizeof(int));
    if (!reg2->hash) {
        exit(1);
    }
    
    // node is not accessed in the loop, so we can leave it NULL
    reg2->node = NULL;
}