#include <stdio.h>

#include <inttypes.h>

extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int weight[2][15][3];
extern int offset[2][15][3];
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
int indices[90]; // Max possible: (2 + list_offset) * max(listXsize[...]) <= assumed 90 for safety
int count = 0;
for (int c = 0; c < 2 + list_offset; c++) {
    for (int i = 0; i < listXsize[c]; i++) {
        indices[count++] = (c << 16) | (i << 8) | 0; // Encode clist, index, and starting comp=0
    }
}
for (int idx = 0; idx < count && perform_wp == 0; idx++) {
    int c = (indices[idx] >> 16) & 0xFF;
    int i = (indices[idx] >> 8) & 0xFF;
    for (comp = 0; comp < 3; comp++) {
        if (weight[c][i][comp] != default_weight || offset[c][i][comp] != 0) {
            perform_wp = 1;
            break;
        }
    }
}
}
