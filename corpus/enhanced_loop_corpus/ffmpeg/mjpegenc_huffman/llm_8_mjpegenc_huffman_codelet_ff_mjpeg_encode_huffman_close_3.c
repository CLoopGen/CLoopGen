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
    int step = 4;
    for (i = 0; i < 256; i += step) {
        if (s->val_count[i + 0]) nval++;
        if (i + 1 < 256 && s->val_count[i + 1]) nval++;
        if (i + 2 < 256 && s->val_count[i + 2]) nval++;
        if (i + 3 < 256 && s->val_count[i + 3]) nval++;
    }
}
