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

quantum_reg *reg1;
quantum_reg *reg2;
int i;
int j;
quantum_reg reg;

void init_vars() {
    const int reg1_size = 2048;
    const int reg2_size = 2048;
    const int reg2_width = 64;

    quantum_reg_node *nodes1 = (quantum_reg_node*)calloc(reg1_size, sizeof(quantum_reg_node));
    quantum_reg_node *nodes2 = (quantum_reg_node*)calloc(reg2_size, sizeof(quantum_reg_node));
    quantum_reg_node *reg_nodes = (quantum_reg_node*)calloc(reg1_size * reg2_size, sizeof(quantum_reg_node));
    int *hash1 = (int*)calloc(reg1_size, sizeof(int));
    int *hash2 = (int*)calloc(reg2_size, sizeof(int));

    for (int idx = 0; idx < reg1_size; ++idx) {
        nodes1[idx].amplitude = 1.0f + 0.5f * idx;
        nodes1[idx].state = idx;
        hash1[idx] = idx % 100;
    }

    for (int idx = 0; idx < reg2_size; ++idx) {
        nodes2[idx].amplitude = 0.8f - 0.3f * idx;
        nodes2[idx].state = idx & 0xFFFFFFFFULL;
        hash2[idx] = idx % 150;
    }

    reg1 = (quantum_reg*)malloc(sizeof(quantum_reg));
    reg2 = (quantum_reg*)malloc(sizeof(quantum_reg));

    reg1->width = 64;
    reg1->size = reg1_size;
    reg1->hashw = 10;
    reg1->node = nodes1;
    reg1->hash = hash1;

    reg2->width = reg2_width;
    reg2->size = reg2_size;
    reg2->hashw = 15;
    reg2->node = nodes2;
    reg2->hash = hash2;

    reg.width = reg1->width + reg2->width;
    reg.size = reg1->size * reg2->size;
    reg.hashw = reg1->hashw;
    reg.node = reg_nodes;
    reg.hash = NULL;
}