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

void init_vars() {
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->width = 32;
    reg->size = 0;
    reg->hashw = 24; // 2^24 ≈ 16.7M entries, ~67MB for int array, targets ~0.01s runtime
    
    reg->node = (quantum_reg_node*)calloc(1 << reg->hashw, sizeof(quantum_reg_node));
    reg->hash = (int*)calloc(1 << reg->hashw, sizeof(int));
}

void loop();