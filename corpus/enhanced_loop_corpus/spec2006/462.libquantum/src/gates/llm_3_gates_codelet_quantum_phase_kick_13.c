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

extern int target;
extern quantum_reg *reg;
extern int i;
extern _Complex float z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping (reverse order traversal)
    // Access nodes in reverse order to change spatial locality and memory access pattern
    for (i = reg->size - 1; i >= 0; i--) {
        if (reg->node[i].state & ((unsigned long long)1 << target))
            reg->node[i].amplitude *= z;
    }
}
