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
if (ape->totalframes > 1) {
    ape->frames[0].size = 0;
    for (i = 1; i < ape->totalframes; i += 2) {
        uint32_t seek_val_i = ape->seektable[i];
        int64_t current_pos = seek_val_i + ape->junklength;
        ape->frames[i].pos = current_pos;
        ape->frames[i].nblocks = ape->blocksperframe;
        ape->frames[i].skip = (current_pos - ape->frames[0].pos) & 3;

        if (i + 1 < ape->totalframes) {
            uint32_t seek_val_next = ape->seektable[i + 1];
            int64_t next_pos = seek_val_next + ape->junklength;
            ape->frames[i + 1].pos = next_pos;
            ape->frames[i + 1].nblocks = ape->blocksperframe;
            ape->frames[i].size = next_pos - current_pos;
            ape->frames[i + 1].skip = (next_pos - ape->frames[0].pos) & 3;
        } else {
            ape->frames[i].size = (ape->junklength + ape->audiodatalength) - current_pos;
        }
    }
}
}
