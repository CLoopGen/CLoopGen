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
    int step = 2;
    for (q = min_quant; q < max_quant + 2; q += step) {
        int idx = trellis_node + q;
        td->nodes[idx].prev_node = -1;
        td->nodes[idx].quant = q;
        if (q + 1 < max_quant + 2) {
            int idx_next = trellis_node + q + 1;
            td->nodes[idx_next].prev_node = -1;
            td->nodes[idx_next].quant = q + 1;
        }
    }
}
