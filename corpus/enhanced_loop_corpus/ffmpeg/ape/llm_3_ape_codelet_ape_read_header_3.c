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
    // Variant 2: Strided memory access pattern with reverse iteration and stride of 2 (simulating non-unit stride)
    // Access every second element in reverse to demonstrate strided, non-consecutive access
    int step = 2;
    int total = ape->totalframes;
    int start = (total - 1) & (~1); // Round down to nearest even index

    for (i = start; i >= 0; i -= step) {
        // Apply logic only on valid indices with strided access
        if (i < total - 1 && ape->bittable[i + 1])
            ape->frames[i].size += 4;
        ape->frames[i].skip <<= 3;
        ape->frames[i].skip += ape->bittable[i];

        // Also process i+1 if within bounds to maintain progressivity, but keep stride primary
        if ((i + 1) < total) {
            if (i + 1 < total - 1 && ape->bittable[i + 2])
                ape->frames[i + 1].size += 4;
            ape->frames[i + 1].skip <<= 3;
            ape->frames[i + 1].skip += ape->bittable[i + 1];
        }
    }
}
