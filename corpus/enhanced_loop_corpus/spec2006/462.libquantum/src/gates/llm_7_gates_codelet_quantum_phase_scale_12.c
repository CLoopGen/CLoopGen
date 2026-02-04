#include <stdio.h>

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

extern quantum_reg *reg;
extern int i;
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    _Complex float local_accum[8];
    int chunk = 8;
    for (i = 0; i < reg->size; i += chunk) {
        for (j = 0; j < chunk && (i + j) < reg->size; j++) {
            local_accum[j] = reg->node[i + j].amplitude * z;
        }
        for (j = 0; j < chunk && (i + j) < reg->size; j++) {
            reg->node[i + j].amplitude = local_accum[j];
        }
    }
}
