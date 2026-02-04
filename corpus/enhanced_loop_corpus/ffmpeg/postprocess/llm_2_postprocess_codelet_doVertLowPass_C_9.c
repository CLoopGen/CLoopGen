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
extern PPContext *c;
extern  int l1;
extern  int l2;
extern  int l3;
extern  int l4;
extern  int l5;
extern  int l6;
extern  int l7;
extern  int l8;
extern  int l9;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (x = 0; x < 8; x++) {
        const int offset = x * 9; // Strided access base
        const uint8_t *s = src + offset;

        const int first = (abs(s[0] - s[l1])) < c->QP ? s[0] : s[l1];
        const int last = (abs(s[l8] - s[l9])) < c->QP ? s[l9] : s[l8];

        int sums[10];
        sums[0] = 4 * first + s[l1] + s[l2] + s[l3] + 4;
        for (int i = 1; i < 9; i++) {
            sums[i] = sums[i-1] - first + s[l3 + i];
        }
        sums[9] = sums[8] - s[l5] + last;

        uint8_t *d = (uint8_t*)(src + offset);
        d[l1] = (sums[0] + sums[2] + 2 * d[l1]) >> 4;
        d[l2] = (sums[1] + sums[3] + 2 * d[l2]) >> 4;
        d[l3] = (sums[2] + sums[4] + 2 * d[l3]) >> 4;
        d[l4] = (sums[3] + sums[5] + 2 * d[l4]) >> 4;
        d[l5] = (sums[4] + sums[6] + 2 * d[l5]) >> 4;
        d[l6] = (sums[5] + sums[7] + 2 * d[l6]) >> 4;
        d[l7] = (sums[6] + sums[8] + 2 * d[l7]) >> 4;
        d[l8] = (sums[7] + sums[9] + 2 * d[l8]) >> 4;
    }
}
