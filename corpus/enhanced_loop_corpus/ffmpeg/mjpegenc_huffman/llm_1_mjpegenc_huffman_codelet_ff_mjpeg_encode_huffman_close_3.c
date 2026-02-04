#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MJpegEncHuffmanContext {
    int val_count[256];
} MJpegEncHuffmanContext;

extern MJpegEncHuffmanContext *s;
extern int i;
extern int nval;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < 16; depth1++) {
    for (int depth2 = 0; depth2 < 16; depth2++) {
        int i = depth1 * 16 + depth2;
        if (s->val_count[i])
            nval++;
    }
}
}
