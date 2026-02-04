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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access pattern over the quantization levels by unrolling and stepping with a fixed stride
    // This changes access order to nodes with non-unit stride, simulating irregular but predictable memory traversal.
    int stride = 2;
    int start_pq, start_q;

    // Process two phases to cover all values due to striding
    for (int phase_pq = 0; phase_pq < stride; phase_pq++) {
        for (int phase_q = 0; phase_q < stride; phase_q++) {
            for (start_pq = min_quant + phase_pq; start_pq < max_quant + 2; start_pq += stride) {
                prev = trellis_node - 16 + start_pq;
                for (start_q = min_quant + phase_q; start_q < max_quant + 2; start_q += stride) {
                    cur = trellis_node + start_q;
                    bits = td->nodes[prev].bits + slice_bits[start_q];
                    error = slice_score[start_q];
                    if (bits > bits_limit)
                        error = 2147483647 / 2;
                    if (td->nodes[prev].score < 2147483647 / 2 && error < 2147483647 / 2)
                        new_score = td->nodes[prev].score + error;
                    else
                        new_score = 2147483647 / 2;
                    if (td->nodes[cur].prev_node == -1 || td->nodes[cur].score >= new_score) {
                        td->nodes[cur].bits = bits;
                        td->nodes[cur].score = new_score;
                        td->nodes[cur].prev_node = prev;
                    }
                }
            }
        }
    }
}
