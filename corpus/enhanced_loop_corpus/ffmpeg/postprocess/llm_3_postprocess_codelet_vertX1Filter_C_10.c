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

extern uint8_t *src;
extern PPContext *co;
extern  int l2;
extern  int l3;
extern  int l4;
extern  int l5;
extern  int l6;
extern  int l7;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[6];
for (x = 0; x < 8; x++) {
    indices[0] = l2 + x;
    indices[1] = l3 + x;
    indices[2] = l4 + x;
    indices[3] = l5 + x;
    indices[4] = l6 + x;
    indices[5] = l7 + x;
    
    int a = src[indices[1]] - src[indices[2]];
    int b = src[indices[2]] - src[indices[3]];
    int c = src[indices[3]] - src[indices[4]];
    int d = ((b) >= 0 ? (b) : (-(b))) - ((((a) >= 0 ? (a) : (-(a))) + ((c) >= 0 ? (c) : (-(c)))) >> 1);
    d = ((d) > (0) ? (d) : (0));
    if (d < co->QP * 2) {
        int v = d * ((-b) > 0 ? 1 : -1);
        src[indices[0]] += v >> 3;
        src[indices[1]] += v >> 2;
        src[indices[2]] += (3 * v) >> 3;
        src[indices[3]] -= (3 * v) >> 3;
        src[indices[4]] -= v >> 2;
        src[indices[5]] -= v >> 3;
    }
}
}
