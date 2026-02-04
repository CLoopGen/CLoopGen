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
int i;
int size = reg->size;
_Complex float local_z = z;
for (i = 0; i < size; i += 2) {
    reg->node[i].amplitude *= local_z;
    if (i + 1 < size) {
        reg->node[i + 1].amplitude *= local_z;
    }
}
}
