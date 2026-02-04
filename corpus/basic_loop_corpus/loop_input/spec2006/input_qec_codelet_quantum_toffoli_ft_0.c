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

int width = 8;
int control1 = 3;
int control2 = 5;
quantum_reg *reg;
int i;
int c1;
int c2;
unsigned long long mask = 0x1FULL << 10;

void init_vars() {
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->width = width;
    reg->size = 2097152; // ~16.8 MB of data: 2M * (sizeof(quantum_reg_node) = 16 bytes)
    reg->hashw = 10;
    
    reg->node = (quantum_reg_node*)calloc(reg->size, sizeof(quantum_reg_node));
    reg->hash = (int*)calloc(1 << reg->hashw, sizeof(int));
    
    for (int idx = 0; idx < reg->size; idx++) {
        reg->node[idx].amplitude = 1.0f + 0.0f * _Complex_I;
        reg->node[idx].state = (unsigned long long)idx * 17 + (idx << (idx % 16));
    }
    
    for (int idx = 0; idx < (1 << reg->hashw); idx++) {
        reg->hash[idx] = idx % reg->size;
    }
}