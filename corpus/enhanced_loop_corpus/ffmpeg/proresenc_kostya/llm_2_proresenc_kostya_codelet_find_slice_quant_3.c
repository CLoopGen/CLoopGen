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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride to simulate non-consecutive node traversal
    // Instead of accessing consecutive q indices, we step by 2, reading every other element.
    for (q = min_quant + 1; q < max_quant + 2; q += 2) {
        if (td->nodes[trellis_node + q].score <= error) {
            error = td->nodes[trellis_node + q].score;
            pq = trellis_node + q;
        }
    }
    // Handle potential missing odd index when max_quant+2 is even
    if ((max_quant + 2 - min_quant - 1) % 2 && q - 1 < max_quant + 2) {
        int idx = trellis_node + q - 1;
        if (td->nodes[idx].score <= error) {
            error = td->nodes[idx].score;
            pq = idx;
        }
    }
}
