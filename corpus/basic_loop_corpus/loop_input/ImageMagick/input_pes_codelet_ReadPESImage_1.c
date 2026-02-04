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

PESColorInfo PESColor[256];
PESBlockInfo blocks[256];
ssize_t i;

void init_vars() {
    for (int idx = 0; idx < 256; idx++) {
        ((unsigned char*)&PESColor[idx].red)[0]   = (unsigned char)(idx * 131 % 256);
        ((unsigned char*)&PESColor[idx].green)[0] = (unsigned char)(idx * 193 % 256);
        ((unsigned char*)&PESColor[idx].blue)[0]  = (unsigned char)(idx * 223 % 256);
        ((unsigned char*)&PESColor[idx].alpha)[0] = (unsigned char)(idx * 71  % 256);
    }
    for (int idx = 0; idx < 256; idx++) {
        blocks[idx].color = &PESColor[0];
        blocks[idx].offset = -1;
    }
    i = 0;
}