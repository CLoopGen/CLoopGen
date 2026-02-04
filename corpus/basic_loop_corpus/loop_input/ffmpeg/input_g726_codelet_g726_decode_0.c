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

typedef struct Float11 {
    uint8_t sign;
    uint8_t exp;
    uint8_t mant;
} Float11;

typedef struct G726Context {
    AVClass *class;
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

void init_vars() {
    c = (G726Context*)calloc(1, sizeof(G726Context));
    if (!c) exit(1);

    c->class = (AVClass*)calloc(1, sizeof(AVClass));
    if (!c->class) exit(1);

    for (int j = 0; j < 2; j++) {
        c->sr[j].sign = 0;
        c->sr[j].exp = 10;
        c->sr[j].mant = 5;
    }

    for (int j = 0; j < 6; j++) {
        c->dq[j].sign = j % 2;
        c->dq[j].exp = (j + 5) % 31;
        c->dq[j].mant = (j + 10) % 127;
    }

    for (int j = 0; j < 2; j++) {
        c->a[j] = j * 100;
        c->pk[j] = j * 50;
    }

    for (int j = 0; j < 6; j++) {
        c->b[j] = j * 20;
    }

    c->ap = 1;
    c->yu = 2048;
    c->yl = 1024;
    c->dms = 512;
    c->dml = 256;
    c->td = 1;
    c->se = 0;
    c->sez = 0;
    c->y = 1000;
    c->code_size = 4;
    c->little_endian = 1;
}