#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <time.h>

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
_Complex float z = 0.70710678118 + 0.70710678118 * I;

void init_vars() {
    const int data_size = 1 << 20; // Approximately 1 million elements
    reg = (quantum_reg *)malloc(sizeof(quantum_reg));
    reg->width = 64;
    reg->size = data_size;
    reg->hashw = 10;
    
    reg->node = (quantum_reg_node *)malloc(data_size * sizeof(quantum_reg_node));
    reg->hash = (int *)malloc((1 << reg->hashw) * sizeof(int));
    
    srand(time(NULL));
    for (i = 0; i < data_size; i++) {
        reg->node[i].amplitude = rand() / (float)RAND_MAX + (rand() / (float)RAND_MAX) * I;
        reg->node[i].state = rand() | ((unsigned long long)rand() << 32);
    }
    
    for (i = 0; i < (1 << reg->hashw); i++) {
        reg->hash[i] = -1;
    }
}