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

extern int control1;
extern int control2;
extern int target;
extern quantum_reg *reg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (reg->size > 0) {
    for (i = 0; i < reg->size; i += 2) {
        int j = i;
        if (j < reg->size) {
            if (reg->node[j].state & ((unsigned long long)1 << control1)) {
                if (reg->node[j].state & ((unsigned long long)1 << control2)) {
                    reg->node[j].state ^= ((unsigned long long)1 << target);
                }
            }
        }
        j = i + 1;
        if (j < reg->size) {
            if (reg->node[j].state & ((unsigned long long)1 << control1)) {
                if (reg->node[j].state & ((unsigned long long)1 << control2)) {
                    reg->node[j].state ^= ((unsigned long long)1 << target);
                }
            }
        }
    }
}
}
