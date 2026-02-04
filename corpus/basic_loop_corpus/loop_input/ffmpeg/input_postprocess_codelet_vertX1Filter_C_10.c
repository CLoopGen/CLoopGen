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

uint8_t *src;
PPContext *co;
int l2;
int l3;
int l4;
int l5;
int l6;
int l7;
int x;

static uint8_t *src_buffer;
static PPContext co_instance;
static AVClass av_class_instance;

void init_vars() {
    const size_t buffer_size = 16777216; // ~16MB to target ~0.01s runtime
    src_buffer = (uint8_t *)calloc(buffer_size, sizeof(uint8_t));
    if (!src_buffer) exit(1);

    src = src_buffer + 1000000; // leave space for negative offsets

    co = &co_instance;
    co->av_class = &av_class_instance;
    co->QP = 10;
    co->cpuCaps = 0;
    co->stride = 4096;
    co->qpStride = 4096;
    co->hChromaSubSample = 1;
    co->vChromaSubSample = 1;
    co->ppMode.lumMode = 1;
    co->ppMode.chromMode = 1;
    co->ppMode.error = 0;
    co->ppMode.minAllowedY = 0;
    co->ppMode.maxAllowedY = 255;
    co->ppMode.maxClippedThreshold.num = 1;
    co->ppMode.maxClippedThreshold.den = 1;
    co->ppMode.maxTmpNoise[0] = 10;
    co->ppMode.maxTmpNoise[1] = 10;
    co->ppMode.maxTmpNoise[2] = 10;
    co->ppMode.baseDcDiff = 100;
    co->ppMode.flatnessThreshold = 20;
    co->ppMode.forcedQuant = 0;

    for (int i = 0; i < 4; i++) {
        co->QP_block[i] = co->QP;
        co->nonBQP_block[i] = co->nonBQP;
        co->pQPb_block[i] = 0;
        co->pQPb2_block[i] = 0;
    }

    for (int i = 0; i < 64; i++) {
        co->mmxDcOffset[i] = 0;
        co->mmxDcThreshold[i] = 100;
    }

    co->packedYOffset = 0;
    co->packedYScale = 1;

    co->stdQPTable = NULL;
    co->nonBQPTable = NULL;
    co->forcedQPTable = NULL;

    co->tempBlocks = NULL;
    co->yHistogram = NULL;
    co->tempDst = NULL;
    co->tempSrc = NULL;
    co->deintTemp = NULL;
    for (int i = 0; i < 3; i++) {
        co->tempBlurred[i] = NULL;
        co->tempBlurredPast[i] = NULL;
    }

    av_class_instance.class_name = "pp_context";
    av_class_instance.category = AV_CLASS_CATEGORY_SWSCALER;

    l2 = -3;
    l3 = -2;
    l4 = -1;
    l5 = 0;
    l6 = 1;
    l7 = 2;

    x = 0;
}