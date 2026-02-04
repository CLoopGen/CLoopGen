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

typedef union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
} OptionDefaultVal;

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    OptionDefaultVal default_val;
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

struct AVClass {
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
};

typedef struct {
    uint16_t style_start;
    uint16_t style_end;
    uint8_t style_flag;
    uint8_t bold;
    uint8_t italic;
    uint8_t underline;
    int color;
    uint8_t alpha;
    uint8_t fontsize;
    uint16_t style_fontID;
} StyleBox;

typedef struct {
    uint16_t hlit_start;
    uint16_t hlit_end;
} HighlightBox;

typedef struct {
    uint8_t hlit_color[4];
} HilightcolorBox;

typedef struct {
    uint16_t fontID;
    char *font;
} FontRecord;

typedef struct {
    uint8_t wrap_flag;
} TextWrapBox;

typedef struct {
    uint16_t fontID;
    const char *font;
    uint8_t fontsize;
    int color;
    uint8_t alpha;
    int back_color;
    uint8_t back_alpha;
    uint8_t bold;
    uint8_t italic;
    uint8_t underline;
    int alignment;
} MovTextDefault;

typedef struct {
    struct AVClass *class;
    StyleBox *s;
    HighlightBox h;
    HilightcolorBox c;
    FontRecord *ftab;
    TextWrapBox w;
    MovTextDefault d;
    uint8_t box_flags;
    uint16_t style_entries;
    uint16_t ftab_entries;
    uint64_t tracksize;
    int size_var;
    int readorder;
    int frame_width;
    int frame_height;
} MovTextContext;

extern MovTextContext *m;
extern int i;

#define TARGET_DATA_SIZE (16 << 20)

static struct AVClass av_class_instance = { .class_name = "mov_text" };

static FontRecord *font_table;
static MovTextContext movtext_context_instance;

void init_vars() {
    font_table = calloc(TARGET_DATA_SIZE / sizeof(FontRecord), sizeof(FontRecord));
    if (!font_table) exit(1);

    for (size_t idx = 0; idx < TARGET_DATA_SIZE / sizeof(FontRecord); idx++) {
        font_table[idx].fontID = (uint16_t)(idx + 1);
        font_table[idx].font = "Arial";
    }

    movtext_context_instance.class = &av_class_instance;
    movtext_context_instance.s = NULL;
    movtext_context_instance.h.hlit_start = 0;
    movtext_context_instance.h.hlit_end = 0;
    for (int j = 0; j < 4; j++)
        movtext_context_instance.c.hlit_color[j] = 0;
    movtext_context_instance.ftab = font_table;
    movtext_context_instance.w.wrap_flag = 0;
    movtext_context_instance.d.fontID = (TARGET_DATA_SIZE / sizeof(FontRecord)) / 2;
    movtext_context_instance.d.font = NULL;
    movtext_context_instance.box_flags = 0;
    movtext_context_instance.style_entries = 0;
    movtext_context_instance.ftab_entries = (uint16_t)(TARGET_DATA_SIZE / sizeof(FontRecord));
    movtext_context_instance.tracksize = TARGET_DATA_SIZE;
    movtext_context_instance.size_var = 0;
    movtext_context_instance.readorder = 0;
    movtext_context_instance.frame_width = 1920;
    movtext_context_instance.frame_height = 1080;

    m = &movtext_context_instance;
    i = 0;
}

MovTextContext *m = &movtext_context_instance;
int i = 0;