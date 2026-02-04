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
extern int pq;
extern  int min_quant;
extern  int max_quant;
extern int error;
extern int bits;
extern int bits_limit;
extern int prev;
extern int cur;
extern int new_score;
extern int slice_bits[16];
extern int slice_score[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score, temp_bits;
    for (pq = min_quant; pq < max_quant + 2; pq++) {
        prev = trellis_node - 16 + pq;
        for (q = min_quant; q < max_quant + 2; q++) {
            cur = trellis_node + q;
            temp_bits = td->nodes[prev].bits + slice_bits[q];
            temp_score = slice_score[q];
            if (temp_bits > bits_limit)
                temp_score = 2147483647 / 2;
            if (td->nodes[prev].score < 2147483647 / 2 && temp_score < 2147483647 / 2)
                new_score = td->nodes[prev].score + temp_score;
            else
                new_score = 2147483647 / 2;
            if (td->nodes[cur].prev_node == -1 || td->nodes[cur].score >= new_score) {
                td->nodes[cur].bits = temp_bits;
                td->nodes[cur].score = new_score;
                td->nodes[cur].prev_node = prev;
            }
        }
    }
}
