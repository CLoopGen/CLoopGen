#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct APEFrame {
    int64_t pos;
    int64_t size;
    int nblocks;
    int skip;
    int64_t pts;
} APEFrame;

typedef struct APEContext {
    uint32_t junklength;
    uint32_t firstframe;
    uint32_t totalsamples;
    int currentframe;
    APEFrame *frames;
    int16_t fileversion;
    int16_t padding1;
    uint32_t descriptorlength;
    uint32_t headerlength;
    uint32_t seektablelength;
    uint32_t wavheaderlength;
    uint32_t audiodatalength;
    uint32_t audiodatalength_high;
    uint32_t wavtaillength;
    uint8_t md5[16];
    uint16_t compressiontype;
    uint16_t formatflags;
    uint32_t blocksperframe;
    uint32_t finalframeblocks;
    uint32_t totalframes;
    uint16_t bps;
    uint16_t channels;
    uint32_t samplerate;
    uint32_t *seektable;
    uint8_t *bittable;
} APEContext;

extern APEContext *ape;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total = ape->totalframes;
    for (i = 0; i < total; i += 2) {
        if (i + 1 < total && ape->bittable[i + 1]) {
            ape->frames[i].size += 4;
            if (i + 1 < total) {
                ape->frames[i + 1].size += 4;
            }
        }
        ape->frames[i].skip = (ape->frames[i].skip << 3) + ape->bittable[i];
        if (i + 1 < total) {
            ape->frames[i + 1].skip = (ape->frames[i + 1].skip << 3) + ape->bittable[i + 1];
        }
    }
}
