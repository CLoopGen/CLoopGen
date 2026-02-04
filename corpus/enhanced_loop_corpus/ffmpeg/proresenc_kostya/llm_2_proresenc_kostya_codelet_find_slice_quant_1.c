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
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // This variant accesses every second element in two separate sequences to create a strided pattern.
    int stride = 2;
    int base_index = trellis_node;
    for (q = min_quant; q < max_quant + 2; q += stride) {
        // First strided access
        if (q < max_quant + 2) {
            td->nodes[base_index + q].prev_node = -1;
            td->nodes[base_index + q].quant = q;
        }
        // Second strided access (if within bounds)
        if (q + 1 < max_quant + 2) {
            td->nodes[base_index + q + 1].prev_node = -1;
            td->nodes[base_index + q + 1].quant = q + 1;
        }
    }
}
