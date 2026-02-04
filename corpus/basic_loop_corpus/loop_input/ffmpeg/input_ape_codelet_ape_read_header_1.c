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

APEContext *ape;
int i;

static APEFrame *frames_data;
static uint32_t *seektable_data;

void init_vars() {
    ape = (APEContext*)calloc(1, sizeof(APEContext));
    if (!ape) exit(1);

    ape->junklength = 1024;
    ape->blocksperframe = 9216;
    ape->totalframes = 131072;

    frames_data = (APEFrame*)calloc(ape->totalframes, sizeof(APEFrame));
    if (!frames_data) exit(1);
    ape->frames = frames_data;

    seektable_data = (uint32_t*)calloc(ape->totalframes, sizeof(uint32_t));
    if (!seektable_data) exit(1);
    ape->seektable = seektable_data;

    for (uint32_t idx = 0; idx < ape->totalframes; idx++) {
        seektable_data[idx] = idx * 4096ULL;
    }

    ape->frames[0].pos = ape->junklength + seektable_data[0];
    ape->frames[0].nblocks = ape->blocksperframe;
    ape->frames[0].skip = 0;
}