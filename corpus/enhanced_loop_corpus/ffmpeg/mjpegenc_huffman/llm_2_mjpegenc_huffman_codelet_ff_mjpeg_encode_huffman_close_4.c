#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MJpegEncHuffmanContext {
    int val_count[256];
} MJpegEncHuffmanContext;

typedef struct PTable {
    int value;
    int prob;
} PTable;

extern MJpegEncHuffmanContext *s;
extern int i;
extern int j;
extern PTable val_counts[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    for (i = 0; i < 256; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        if (idx1 < 256 && s->val_count[idx1]) {
            val_counts[j].value = idx1;
            val_counts[j].prob = s->val_count[idx1];
            j++;
        }
        if (idx2 < 256 && s->val_count[idx2]) {
            val_counts[j].value = idx2;
            val_counts[j].prob = s->val_count[idx2];
            j++;
        }
    }
}
