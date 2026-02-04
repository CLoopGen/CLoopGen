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

int mbWidth;
PPContext *c;
int i;

void init_vars() {
    mbWidth = 131072; // ~1MB of data written (each int8_t is 1 byte)

    c = (PPContext *)calloc(1, sizeof(PPContext));
    if (!c) exit(1);

    c->av_class = NULL;
    c->tempBlocks = NULL;
    c->yHistogram = NULL;
    c->packedYOffset = 0;
    c->packedYScale = 0;
    for (int j = 0; j < 3; j++) {
        c->tempBlurred[j] = NULL;
        c->tempBlurredPast[j] = NULL;
    }
    c->tempDst = NULL;
    c->tempSrc = NULL;
    c->deintTemp = NULL;
    c->pQPb = 0;
    c->pQPb2 = 0;
    for (int j = 0; j < 4; j++) {
        c->pQPb_block[j] = 0;
        c->pQPb2_block[j] = 0;
        c->QP_block[j] = 0;
        c->nonBQP_block[j] = 0;
    }
    for (int j = 0; j < 64; j++) {
        c->mmxDcOffset[j] = 0;
        c->mmxDcThreshold[j] = 0;
    }

    c->stdQPTable = (int8_t *)calloc(mbWidth, sizeof(int8_t));
    c->nonBQPTable = (int8_t *)calloc(mbWidth, sizeof(int8_t));
    c->forcedQPTable = (int8_t *)calloc(mbWidth, sizeof(int8_t));
    if (!c->stdQPTable || !c->nonBQPTable || !c->forcedQPTable) exit(1);

    c->QP = 0;
    c->nonBQP = 0;
    c->frameNum = 0;
    c->cpuCaps = 0;
    c->qpStride = mbWidth;
    c->stride = 0;
    c->hChromaSubSample = 1;
    c->vChromaSubSample = 1;

    c->ppMode.lumMode = 0;
    c->ppMode.chromMode = 0;
    c->ppMode.error = 0;
    c->ppMode.minAllowedY = 0;
    c->ppMode.maxAllowedY = 255;
    c->ppMode.maxClippedThreshold.num = 1;
    c->ppMode.maxClippedThreshold.den = 1;
    c->ppMode.maxTmpNoise[0] = 0;
    c->ppMode.maxTmpNoise[1] = 0;
    c->ppMode.maxTmpNoise[2] = 0;
    c->ppMode.baseDcDiff = 0;
    c->ppMode.flatnessThreshold = 0;
    c->ppMode.forcedQuant = 1;
}