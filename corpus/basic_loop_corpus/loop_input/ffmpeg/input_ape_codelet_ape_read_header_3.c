#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
static uint8_t *bittable_data;

void init_vars() {
    const uint32_t target_data_size = 32 * 1024 * 1024; // ~32MB for sufficient runtime (~0.01s)
    const uint32_t estimated_frames = target_data_size / sizeof(APEFrame);
    const uint32_t totalframes = (estimated_frames > 0) ? estimated_frames : 1;

    frames_data = calloc(totalframes, sizeof(APEFrame));
    bittable_data = malloc(totalframes * sizeof(uint8_t));

    if (!frames_data || !bittable_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint32_t j = 0; j < totalframes; j++) {
        frames_data[j].pos = j * 1000;
        frames_data[j].size = 1024;
        frames_data[j].nblocks = 512;
        frames_data[j].skip = 1;
        frames_data[j].pts = j * 100;
        bittable_data[j] = (j % 255) + 1;
    }

    ape = malloc(sizeof(APEContext));
    if (!ape) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(ape, 0, sizeof(APEContext));
    ape->junklength = 0;
    ape->firstframe = 0;
    ape->totalsamples = 0;
    ape->currentframe = 0;
    ape->frames = frames_data;
    ape->fileversion = 3980;
    ape->padding1 = 0;
    ape->descriptorlength = 52;
    ape->headerlength = 32;
    ape->seektablelength = 0;
    ape->wavheaderlength = 120;
    ape->audiodatalength = 0;
    ape->audiodatalength_high = 0;
    ape->wavtaillength = 0;
    memset(ape->md5, 0, 16);
    ape->compressiontype = 2000;
    ape->formatflags = 0;
    ape->blocksperframe = 73728;
    ape->finalframeblocks = 0;
    ape->totalframes = totalframes;
    ape->bps = 16;
    ape->channels = 2;
    ape->samplerate = 44100;
    ape->seektable = NULL;
    ape->bittable = bittable_data;

    i = 0;
}