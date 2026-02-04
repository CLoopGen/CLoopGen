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
for (i = 0; i < 256; i++) {
    if (!s->val_count[i]) continue;
    val_counts[j].value = i;
    val_counts[j].prob = s->val_count[i];
    j++;
    if (j >= 257) break;
}
}
