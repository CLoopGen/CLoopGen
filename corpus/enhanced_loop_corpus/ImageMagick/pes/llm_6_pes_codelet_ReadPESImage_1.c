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
    for (; i < 256L; i++) {
        blocks[i].color = PESColor + i;
        blocks[i].offset = (i > 0) ? blocks[i-1].offset + 1 : 0;
    }
}
