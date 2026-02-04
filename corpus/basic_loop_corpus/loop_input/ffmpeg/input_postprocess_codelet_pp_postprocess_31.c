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
    const void *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(void **, void *, const char *, int);
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

int8_t *QP_store;
PPContext *c;
int i;
int count;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    const int array_len = data_size / sizeof(int8_t);

    QP_store = (int8_t*)aligned_alloc(32, data_size);
    c = (PPContext*)aligned_alloc(32, sizeof(PPContext));

    if (!QP_store || !c) {
        exit(1);
    }

    c->stdQPTable = (int8_t*)aligned_alloc(32, data_size);
    if (!c->stdQPTable) {
        exit(1);
    }

    for (int j = 0; j < array_len; j++) {
        QP_store[j] = (int8_t)(j & 0xFF);
    }

    i = 0;
    count = array_len;

    c->ppMode.lumMode = 1;
    c->ppMode.chromMode = 1;
    c->ppMode.error = 0;
    c->ppMode.minAllowedY = 0;
    c->ppMode.maxAllowedY = 255;
    c->ppMode.maxClippedThreshold.num = 1;
    c->ppMode.maxClippedThreshold.den = 1;
    c->ppMode.maxTmpNoise[0] = 10;
    c->ppMode.maxTmpNoise[1] = 10;
    c->ppMode.maxTmpNoise[2] = 10;
    c->ppMode.baseDcDiff = 128;
    c->ppMode.flatnessThreshold = 20;
    c->ppMode.forcedQuant = 0;

    c->QP = 10;
    c->nonBQP = 12;
    c->frameNum = 0;
    c->cpuCaps = 0;
    c->qpStride = 16;
    c->stride = 16;
    c->hChromaSubSample = 1;
    c->vChromaSubSample = 1;

    for (int j = 0; j < 4; j++) {
        c->QP_block[j] = c->QP;
        c->nonBQP_block[j] = c->nonBQP;
        c->pQPb_block[j] = 0;
        c->pQPb2_block[j] = 0;
    }

    for (int j = 0; j < 64; j++) {
        c->mmxDcOffset[j] = 128;
        c->mmxDcThreshold[j] = 10;
    }

    c->packedYOffset = 0;
    c->packedYScale = 1;
    c->pQPb = 0;
    c->pQPb2 = 0;

    c->tempBlocks = NULL;
    c->yHistogram = NULL;
    c->tempDst = NULL;
    c->tempSrc = NULL;
    c->deintTemp = NULL;
    c->av_class = NULL;
    c->nonBQPTable = NULL;
    c->forcedQPTable = NULL;

    for (int j = 0; j < 3; j++) {
        c->tempBlurred[j] = NULL;
        c->tempBlurredPast[j] = NULL;
    }
}