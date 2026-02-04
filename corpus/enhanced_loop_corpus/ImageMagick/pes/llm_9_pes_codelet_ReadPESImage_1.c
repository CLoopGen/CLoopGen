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
    for (; i < 128L; i++) {
        blocks[2*i].offset = 0;
        blocks[2*i].color = &PESColor[2*i];
        blocks[2*i+1].offset = -1;
        blocks[2*i+1].color = &PESColor[2*i+1];
    }
}
