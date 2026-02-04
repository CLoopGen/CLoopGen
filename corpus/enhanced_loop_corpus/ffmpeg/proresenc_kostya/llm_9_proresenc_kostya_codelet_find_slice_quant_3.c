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
    int step = 1;
    for (q = min_quant + 1; q < max_quant + 2; q += step) {
        int current_score = td->nodes[trellis_node + q].score;
        int threshold = error - 5;
        if (current_score <= error) {
            error = current_score;
            pq = trellis_node + q;
        }
        if (current_score > threshold && q % 3 == 0) {
            step = 2;
        } else {
            step = 1;
        }
    }
}
