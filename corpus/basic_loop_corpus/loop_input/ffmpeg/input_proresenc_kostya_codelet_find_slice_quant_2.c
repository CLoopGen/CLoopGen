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

int trellis_node = 32;
ProresThreadData *td;
int q;
int pq;
int min_quant = 0;
int max_quant = 15;
int error;
int bits;
int bits_limit = 10000;
int prev;
int cur;
int new_score;
int slice_bits[16];
int slice_score[16];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        slice_bits[i] = i * 50 + 10;
        slice_score[i] = i * 100 + 20;
    }

    td = aligned_alloc(32, sizeof(ProresThreadData));
    if (!td) exit(1);

    td->nodes = aligned_alloc(32, sizeof(struct TrellisNode) * 128);
    if (!td->nodes) exit(1);

    for (int i = 0; i < 128; i++) {
        td->nodes[i].prev_node = -1;
        td->nodes[i].quant = 0;
        td->nodes[i].bits = 0;
        td->nodes[i].score = 2147483647 / 2;
    }

    trellis_node = 32;
    bits_limit = 10000;
}