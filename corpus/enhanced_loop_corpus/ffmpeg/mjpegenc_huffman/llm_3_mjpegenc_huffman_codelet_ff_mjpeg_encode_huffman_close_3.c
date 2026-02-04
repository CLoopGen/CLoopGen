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



void loop() {
    int indices[256];
    for (int j = 0; j < 256; j++) {
        indices[j] = j;
    }
    for (i = 0; i < 256; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (s->val_count[idx])
            nval++;
    }
}
