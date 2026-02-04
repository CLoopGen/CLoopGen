#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
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

int control = 3;
int target = 7;
quantum_reg *reg;
int i;
_Complex float z = 1.0f + 0.5f * _Complex_I;

void init_vars() {
    const int data_size_mb = 64;
    const int elements_per_mb = (1 << 20) / sizeof(quantum_reg_node);
    const int total_elements = data_size_mb * elements_per_mb;

    reg = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg->node = (quantum_reg_node*)malloc(total_elements * sizeof(quantum_reg_node));
    reg->hash = (int*)malloc((1 << 16) * sizeof(int));
    
    reg->width = 16;
    reg->size = total_elements;
    reg->hashw = 16;

    for (int idx = 0; idx < total_elements; idx++) {
        reg->node[idx].amplitude = (float)(idx % 1000) + (float)(idx % 789) * _Complex_I;
        reg->node[idx].state = ((unsigned long long)idx << 10) | 0x3FF;
    }

    for (int idx = 0; idx < (1 << 16); idx++) {
        reg->hash[idx] = -1;
    }

    z = 0.8f + 0.6f * _Complex_I;
    control = 10;
    target = 5;
}