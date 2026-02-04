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

MJpegEncHuffmanContext *s;
int i;
int j;
PTable val_counts[257];

void init_vars() {
    s = (MJpegEncHuffmanContext *)malloc(sizeof(MJpegEncHuffmanContext));
    if (!s) exit(1);

    for (int idx = 0; idx < 256; idx++) {
        s->val_count[idx] = rand() % 2 ? rand() % 1000 + 1 : 0;
    }

    j = 0;
}