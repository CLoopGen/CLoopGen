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

int trellis_node = 0;
ProresThreadData *td;
int q;
int min_quant = 1;
int max_quant = 1000;

void init_vars() {
    td = (ProresThreadData*)aligned_alloc(16, sizeof(ProresThreadData));
    size_t node_count = max_quant + 3;
    td->nodes = (struct TrellisNode*)aligned_alloc(16, node_count * sizeof(struct TrellisNode));
    for (size_t i = 0; i < node_count; i++) {
        td->nodes[i].prev_node = 0;
        td->nodes[i].quant = 0;
        td->nodes[i].bits = 0;
        td->nodes[i].score = 0;
    }
    trellis_node = 0;
}