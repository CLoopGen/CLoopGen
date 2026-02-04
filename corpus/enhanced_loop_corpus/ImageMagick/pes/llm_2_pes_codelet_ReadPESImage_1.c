#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PESColorInfo {
    const unsigned char red;
    const unsigned char green;
    const unsigned char blue;
    const unsigned char alpha;
} PESColorInfo;

typedef struct _PESBlockInfo {
    const PESColorInfo *color;
    ssize_t offset;
} PESBlockInfo;

extern  PESColorInfo PESColor[256];
extern PESBlockInfo blocks[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first
    for (i = 0; i < 256L; i += 2) {
        blocks[i].offset = 0;
        blocks[i].color = PESColor;
    }
    for (i = 1; i < 256L; i += 2) {
        blocks[i].offset = 0;
        blocks[i].color = PESColor;
    }
}
