#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVOptionType {
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY,
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE,
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE,
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
};

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
    double min;
    double max;
    int flags;
    const char *unit;
};

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

typedef struct FineSignature {
    struct FineSignature *next;
    struct FineSignature *prev;
    uint64_t pts;
    uint32_t index;
    uint8_t confidence;
    uint8_t words[5];
    uint8_t framesig[76];
} FineSignature;

typedef struct CoarseSignature {
    uint8_t data[5][31];
    struct FineSignature *first;
    struct FineSignature *last;
    struct CoarseSignature *next;
} CoarseSignature;

typedef struct StreamContext {
    AVRational time_base;
    int w;
    int h;
    int divide;
    FineSignature *finesiglist;
    FineSignature *curfinesig;
    CoarseSignature *coarsesiglist;
    CoarseSignature *coarseend;
    CoarseSignature *curcoarsesig1;
    CoarseSignature *curcoarsesig2;
    int coarsecount;
    int midcoarse;
    uint32_t lastindex;
    int exported;
} StreamContext;

typedef struct SignatureContext {
    const AVClass *class;
    int mode;
    int nb_inputs;
    char *filename;
    int format;
    int thworddist;
    int thcomposdist;
    int thl1;
    int thdi;
    int thit;
    uint8_t l1distlut[29403];
    StreamContext *streamcontexts;
} SignatureContext;

SignatureContext *sc;
uint8_t *first;
uint8_t *second;
unsigned int i;
unsigned int dist;
uint8_t f;
uint8_t s;

void init_vars() {
    sc = (SignatureContext *)calloc(1, sizeof(SignatureContext));
    if (!sc) return;

    sc->l1distlut[243 * 242 / 2 - (243 - 100) * (242 - 100) / 2 + 50 - 1] = 150;
    sc->l1distlut[243 * 242 / 2 - (243 - 50) * (242 - 50) / 2 + 100 - 1] = 150;

    size_t array_size = 380 / 5;
    first = (uint8_t *)calloc(array_size, sizeof(uint8_t));
    second = (uint8_t *)calloc(array_size, sizeof(uint8_t));
    if (!first || !second) return;

    for (size_t idx = 0; idx < array_size; idx++) {
        first[idx] = (uint8_t)((idx * 7) % 244);
        second[idx] = (uint8_t)((idx * 11) % 244);
    }

    dist = 0;
}