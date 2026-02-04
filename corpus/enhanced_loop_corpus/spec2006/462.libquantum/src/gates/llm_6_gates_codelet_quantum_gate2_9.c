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

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int shift_val = reg->hashw;
    int limit = 1 << shift_val;
    for (i = 0; i < limit; i++) {
        reg->hash[i] = 0;
        reg->hash[limit - 1 - i] = 0; // WAW dependency introduced: writing twice per iteration (though indices may overlap only at center)
    }
}
