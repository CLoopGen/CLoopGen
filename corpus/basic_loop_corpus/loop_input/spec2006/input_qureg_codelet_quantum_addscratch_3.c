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

extern int bits;
extern quantum_reg *reg;
extern int i;
extern unsigned long long l;

int bits = 3;
quantum_reg *reg;
int i;
unsigned long long l;

void init_vars() {
    // Allocate reg structure
    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    
    // Set parameters
    reg->width = 64;
    reg->hashw = 10;
    
    // Target data size ~16MB of node data
    // Each node is sizeof(quantum_reg_node) = 16 bytes (assuming _Complex float is 8 bytes, ull is 8)
    // So for 16MB: 16*1024*1024 / 16 = 1048576 nodes
    reg->size = 1048576;
    
    // Allocate nodes
    reg->node = (quantum_reg_node*)malloc(reg->size * sizeof(quantum_reg_node));
    
    // Initialize node data
    for (int idx = 0; idx < reg->size; idx++) {
        reg->node[idx].amplitude = 1.0f + 0.0f * _Complex_I;
        reg->node[idx].state = idx & 0xFFFFFFFFULL;
    }
    
    // Allocate hash table (not used in loop but part of struct)
    reg->hash = (int*)malloc((1 << reg->hashw) * sizeof(int));
    for (int idx = 0; idx < (1 << reg->hashw); idx++) {
        reg->hash[idx] = -1;
    }
}