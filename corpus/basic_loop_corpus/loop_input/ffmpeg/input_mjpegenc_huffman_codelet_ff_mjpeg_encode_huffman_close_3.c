#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MJpegEncHuffmanContext {
    int val_count[256];
} MJpegEncHuffmanContext;

MJpegEncHuffmanContext *s;
int i;
int nval;

void init_vars() {
    s = (MJpegEncHuffmanContext*)malloc(sizeof(MJpegEncHuffmanContext));
    if (!s) {
        exit(1);
    }
    for (int idx = 0; idx < 256; idx++) {
        s->val_count[idx] = rand() % 2; // Randomly assign 0 or 1 to trigger conditional increment
    }
    i = 0;
    nval = 0;
}