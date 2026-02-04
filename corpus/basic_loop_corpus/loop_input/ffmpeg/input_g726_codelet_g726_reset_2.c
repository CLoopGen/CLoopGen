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

struct AVOptionRanges {
    int dummy;
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

typedef struct Float11 {
    uint8_t sign;
    uint8_t exp;
    uint8_t mant;
} Float11;

typedef struct G726Tables {
    const int *quant;
    const int16_t *iquant;
    const int16_t *W;
    const uint8_t *F;
} G726Tables;

typedef struct G726Context {
    AVClass *class;
    G726Tables tbls;
    Float11 sr[2];
    Float11 dq[6];
    int a[2];
    int b[6];
    int pk[2];
    int ap;
    int yu;
    int yl;
    int dms;
    int dml;
    int td;
    int se;
    int sez;
    int y;
    int code_size;
    int little_endian;
} G726Context;

G726Context *c;
int i;

static AVClass av_class_instance;
static Float11 sr_init[2] = {{0, 0, 0}, {0, 0, 0}};
static int pk_init[2] = {0, 0};
static const int quant_data[256];
static const int16_t iquant_data[256];
static const int16_t W_data[16];
static const uint8_t F_data[16];

void init_vars() {
    c = malloc(sizeof(G726Context));
    if (!c) return;

    c->class = &av_class_instance;
    c->tbls.quant = quant_data;
    c->tbls.iquant = iquant_data;
    c->tbls.W = W_data;
    c->tbls.F = F_data;

    for (int j = 0; j < 2; j++) {
        c->sr[j] = sr_init[j];
        c->pk[j] = pk_init[j];
    }

    for (int j = 0; j < 6; j++) {
        c->dq[j] = (Float11){0};
    }

    c->ap = 0;
    c->yu = 0;
    c->yl = 0;
    c->dms = 0;
    c->dml = 0;
    c->td = 0;
    c->se = 0;
    c->sez = 0;
    c->y = 0;
    c->code_size = 4;
    c->little_endian = 0;

    for (int j = 0; j < 2; j++) {
        c->a[j] = 0;
    }
    for (int j = 0; j < 6; j++) {
        c->b[j] = 0;
    }
}