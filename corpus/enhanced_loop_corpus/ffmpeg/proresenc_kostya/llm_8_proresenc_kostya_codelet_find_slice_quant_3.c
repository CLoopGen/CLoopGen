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
    for (q = min_quant; q < max_quant + 3; q += 2) {
        int index1 = trellis_node + q;
        int index2 = trellis_node + q + 1;
        if (q + 1 < max_quant + 3) {
            if (td->nodes[index1].score <= error) {
                error = td->nodes[index1].score;
                pq = index1;
            }
            if (td->nodes[index2].score <= error) {
                error = td->nodes[index2].score;
                pq = index2;
            }
        } else {
            if (td->nodes[index1].score <= error) {
                error = td->nodes[index1].score;
                pq = index1;
            }
        }
    }
}
