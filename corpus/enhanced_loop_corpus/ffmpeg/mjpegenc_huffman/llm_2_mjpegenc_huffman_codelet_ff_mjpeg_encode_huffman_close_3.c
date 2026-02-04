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
    int *val_count_ptr = s->val_count;
    for (i = 0; i < 256; i += 4) {
        if (val_count_ptr[i + 0]) nval++;
        if (i + 1 < 256 && val_count_ptr[i + 1]) nval++;
        if (i + 2 < 256 && val_count_ptr[i + 2]) nval++;
        if (i + 3 < 256 && val_count_ptr[i + 3]) nval++;
    }
}
