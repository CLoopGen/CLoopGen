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
    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->hashw = 20;  // 2^20 ≈ 1M entries, sufficient for ~0.01 sec runtime
    reg->width = 64;
    reg->size = 1 << reg->hashw;
    reg->node = (quantum_reg_node *)calloc(reg->size, sizeof(quantum_reg_node));
    reg->hash = (int *)calloc(1 << reg->hashw, sizeof(int));
}

// End of file