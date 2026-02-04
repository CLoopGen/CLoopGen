#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB
} AVClassCategory;

typedef struct AVOption {
} AVOption;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct PPMode {
    int lumMode;
    int chromMode;
    int error;
    int minAllowedY;
    int maxAllowedY;
    AVRational maxClippedThreshold;
    int maxTmpNoise[3];
    int baseDcDiff;
    int flatnessThreshold;
    int forcedQuant;
} PPMode;

typedef struct PPContext {
    const AVClass *av_class;
    uint8_t *tempBlocks;
    uint64_t *yHistogram;
    uint64_t packedYOffset __attribute__((aligned(8)));
    uint64_t packedYScale __attribute__((aligned(8)));
    uint8_t *tempBlurred[3];
    int32_t *tempBlurredPast[3];
    uint8_t *tempDst;
    uint8_t *tempSrc;
    uint8_t *deintTemp;
    uint64_t pQPb __attribute__((aligned(8)));
    uint64_t pQPb2 __attribute__((aligned(8)));
    uint64_t pQPb_block[4] __attribute__((aligned(32)));
    uint64_t pQPb2_block[4] __attribute__((aligned(32)));
    uint64_t mmxDcOffset[64] __attribute__((aligned(32)));
    uint64_t mmxDcThreshold[64] __attribute__((aligned(32)));
    int8_t *stdQPTable;
    int8_t *nonBQPTable;
    int8_t *forcedQPTable;
    int QP;
    int nonBQP;
    int QP_block[4] __attribute__((aligned(32)));
    int nonBQP_block[4] __attribute__((aligned(32)));
    int frameNum;
    int cpuCaps;
    int qpStride;
    int stride;
    int hChromaSubSample;
    int vChromaSubSample;
    PPMode ppMode;
} PPContext;

PPContext *c;
int width;
int height;
int i;

void init_vars() {
    width = 1920;
    height = 1080;
    
    c = (PPContext*)calloc(1, sizeof(PPContext));
    if (!c) return;
    
    c->yHistogram = (uint64_t*)aligned_alloc(8, 256 * sizeof(uint64_t));
    if (!c->yHistogram) return;
    
    for (int j = 0; j < 256; j++) {
        c->yHistogram[j] = 0;
    }
    
    c->av_class = (AVClass*)calloc(1, sizeof(AVClass));
    c->tempBlocks = (uint8_t*)calloc(1, 1024 * 1024);
    c->packedYOffset = 0;
    c->packedYScale = 1;
    c->tempDst = (uint8_t*)calloc(1, width * height);
    c->tempSrc = (uint8_t*)calloc(1, width * height);
    c->deintTemp = (uint8_t*)calloc(1, width * height);
    c->pQPb = 1;
    c->pQPb2 = 2;
    for (int j = 0; j < 4; j++) {
        c->pQPb_block[j] = j + 1;
        c->pQPb2_block[j] = j + 2;
        c->QP_block[j] = 16 + j;
        c->nonBQP_block[j] = 12 + j;
    }
    for (int j = 0; j < 64; j++) {
        c->mmxDcOffset[j] = j * 10;
        c->mmxDcThreshold[j] = j * 5;
    }
    c->stdQPTable = (int8_t*)calloc(1, 52);
    c->nonBQPTable = (int8_t*)calloc(1, 52);
    c->forcedQPTable = (int8_t*)calloc(1, 52);
    for (int j = 0; j < 52; j++) {
        c->stdQPTable[j] = j;
        c->nonBQPTable[j] = j - 10;
        c->forcedQPTable[j] = j + 5;
    }
    c->QP = 20;
    c->nonBQP = 16;
    c->frameNum = 0;
    c->cpuCaps = 0;
    c->qpStride = width >> 4;
    c->stride = width;
    c->hChromaSubSample = 1;
    c->vChromaSubSample = 1;
    
    c->ppMode.lumMode = 1;
    c->ppMode.chromMode = 1;
    c->ppMode.error = 0;
    c->ppMode.minAllowedY = 0;
    c->ppMode.maxAllowedY = 255;
    c->ppMode.maxClippedThreshold.num = 1;
    c->ppMode.maxClippedThreshold.den = 10;
    c->ppMode.maxTmpNoise[0] = 10;
    c->ppMode.maxTmpNoise[1] = 10;
    c->ppMode.maxTmpNoise[2] = 10;
    c->ppMode.baseDcDiff = 8;
    c->ppMode.flatnessThreshold = 20;
    c->ppMode.forcedQuant = 0;
}