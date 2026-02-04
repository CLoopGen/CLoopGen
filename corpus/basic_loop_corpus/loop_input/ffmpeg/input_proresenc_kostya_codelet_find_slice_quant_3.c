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

int trellis_node = 1000;
ProresThreadData *td;
int q;
int pq;
int min_quant = 0;
int max_quant = 2000;
int error = 1000000;

void init_vars() {
    td = aligned_alloc(16, sizeof(ProresThreadData));
    td->nodes = aligned_alloc(16, (trellis_node + max_quant + 10) * sizeof(struct TrellisNode));

    for (int i = 0; i < trellis_node + max_quant + 10; i++) {
        td->nodes[i].score = (i % 2000) - 1000;
        td->nodes[i].prev_node = i - 1;
        td->nodes[i].quant = i % 64;
        td->nodes[i].bits = i % 32;
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2048; j++)
            td->blocks[i][j] = rand() % 1024;

    for (int i = 0; i < 256; i++)
        td->emu_buf[i] = rand() % 65536;

    for (int i = 0; i < 64; i++) {
        td->custom_q[i] = rand() % 256;
        td->custom_chroma_q[i] = rand() % 256;
    }
}