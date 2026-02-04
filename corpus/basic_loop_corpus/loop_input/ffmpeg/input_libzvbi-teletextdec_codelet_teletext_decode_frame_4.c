#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

struct AVOptionRanges {
    int dummy;
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

typedef struct AVPicture {
    uint8_t *data[8];
    int linesize[8];
} AVPicture;

enum AVSubtitleType {
    SUBTITLE_NONE,
    SUBTITLE_BITMAP,
    SUBTITLE_TEXT,
    SUBTITLE_ASS
};

typedef struct AVSubtitleRect {
    int x;
    int y;
    int w;
    int h;
    int nb_colors;
    AVPicture pict;
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text;
    char *ass;
    int flags;
} AVSubtitleRect;

typedef struct TeletextPage {
    AVSubtitleRect *sub_rect;
    int pgno;
    int subno;
    int64_t pts;
} TeletextPage;

typedef struct TeletextContext {
    AVClass *class;
    char *pgno;
    int default_region;
    int x_offset;
    int y_offset;
    int format_id;
    int chop_top;
    int sub_duration;
    int transparent_bg;
    int opacity;
    int chop_spaces;
    int lines_processed;
    TeletextPage *pages;
    int nb_pages;
    int64_t pts;
    int handler_ret;
    int *vbi;
    int sliced[64];
    int readorder;
    uint8_t subtitle_map[2048];
    int last_pgno;
    int last_p5;
    int last_ass_alignment;
} TeletextContext;

TeletextContext *ctx;
int i;

void init_vars() {
    ctx = malloc(sizeof(TeletextContext));
    if (!ctx) return;

    ctx->class = malloc(sizeof(AVClass));
    if (ctx->class) {
        ctx->class->class_name = strdup("teletext");
        ctx->class->item_name = NULL;
        ctx->class->option = NULL;
        ctx->class->version = 1;
        ctx->class->log_level_offset_offset = 0;
        ctx->class->parent_log_context_offset = 0;
        ctx->class->child_next = NULL;
        ctx->class->child_class_next = NULL;
        ctx->class->category = AV_CLASS_CATEGORY_INPUT;
        ctx->class->get_category = NULL;
        ctx->class->query_ranges = NULL;
    }

    ctx->pgno = strdup("default");
    ctx->default_region = 0;
    ctx->x_offset = 0;
    ctx->y_offset = 0;
    ctx->format_id = 0;
    ctx->chop_top = 0;
    ctx->sub_duration = 1000;
    ctx->transparent_bg = 1;
    ctx->opacity = 255;
    ctx->chop_spaces = 1;
    ctx->lines_processed = 0;

    ctx->nb_pages = 100000;
    ctx->pages = calloc(ctx->nb_pages, sizeof(TeletextPage));
    if (ctx->pages) {
        for (int j = 0; j < ctx->nb_pages; j++) {
            ctx->pages[j].sub_rect = NULL;
            ctx->pages[j].pgno = j + 100;
            ctx->pages[j].subno = j;
            ctx->pages[j].pts = j * 1000LL;
        }
    }

    ctx->pts = 0;
    ctx->handler_ret = 0;
    ctx->vbi = calloc(64, sizeof(int));
    for (int j = 0; j < 64; j++)
        ctx->sliced[j] = j;
    ctx->readorder = 0;
    for (int j = 0; j < 2048; j++)
        ctx->subtitle_map[j] = j % 256;
    ctx->last_pgno = 100;
    ctx->last_p5 = 0;
    ctx->last_ass_alignment = 2;
}