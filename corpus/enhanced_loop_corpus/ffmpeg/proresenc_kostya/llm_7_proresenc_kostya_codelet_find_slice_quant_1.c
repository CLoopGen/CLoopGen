#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct TrellisNode {
    int prev_node;
    int quant;
    int bits;
    int score;
};


typedef struct ProresThreadData {
    int16_t blocks[4][2048] __attribute__((aligned(16)));
    uint16_t emu_buf[256] __attribute__((aligned(16)));
    int16_t custom_q[64];
    int16_t custom_chroma_q[64];
    struct TrellisNode *nodes;
} ProresThreadData;

extern int trellis_node;
extern ProresThreadData *td;
extern int q;
extern  int min_quant;
extern  int max_quant;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    struct TrellisNode *node_base = &td->nodes[trellis_node];
    for (q = min_quant; q < max_quant + 2; q++) {
        struct TrellisNode temp_node;
        temp_node.prev_node = -1;
        temp_node.quant = q;
        node_base[q] = temp_node;
    }
}
