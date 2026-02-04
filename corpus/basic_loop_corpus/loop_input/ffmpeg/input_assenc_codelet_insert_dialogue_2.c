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

typedef struct DialogueLine {
    int readorder;
    char *line;
    struct DialogueLine *prev;
    struct DialogueLine *next;
} DialogueLine;

typedef struct ASSContext {
    const AVClass *class;
    int expected_readorder;
    DialogueLine *dialogue_cache;
    DialogueLine *last_added_dialogue;
    int cache_size;
    int ssa_mode;
    int ignore_readorder;
    uint8_t *trailer;
    size_t trailer_size;
} ASSContext;

ASSContext *ass;
DialogueLine *dialogue;
DialogueLine *cur;
DialogueLine *next;
DialogueLine *prev;

static AVClass av_class_instance = {
    .class_name = "ass_context",
    .category = AV_CLASS_CATEGORY_FILTER
};

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of data to target 0.01s runtime

static DialogueLine* dialogue_pool;
static char* line_buffer;

void init_vars() {
    // Allocate large pool of dialogue lines
    dialogue_pool = calloc(DATA_SIZE / sizeof(DialogueLine), sizeof(DialogueLine));
    if (!dialogue_pool) exit(1);

    // Allocate shared line content
    line_buffer = malloc(DATA_SIZE);
    if (!line_buffer) exit(1);
    memset(line_buffer, 'A', DATA_SIZE);
    for (size_t i = 0; i < DATA_SIZE; i += 100) {
        line_buffer[i] = '\0';
    }

    // Initialize each dialogue line in a chain
    for (int i = 0; i < DATA_SIZE / sizeof(DialogueLine); ++i) {
        dialogue_pool[i].readorder = i + 1;
        dialogue_pool[i].line = &line_buffer[i * 100 % DATA_SIZE];
        dialogue_pool[i].prev = (i == 0) ? NULL : &dialogue_pool[i-1];
        dialogue_pool[i].next = (i == DATA_SIZE / sizeof(DialogueLine) - 1) ? NULL : &dialogue_pool[i+1];
    }

    // Setup global context
    ass = malloc(sizeof(ASSContext));
    if (!ass) exit(1);

    ass->class = &av_class_instance;
    ass->expected_readorder = 1;
    ass->dialogue_cache = &dialogue_pool[0];
    ass->last_added_dialogue = &dialogue_pool[DATA_SIZE / sizeof(DialogueLine) - 1];
    ass->cache_size = DATA_SIZE / sizeof(DialogueLine);
    ass->ssa_mode = 0;
    ass->ignore_readorder = 0;
    ass->trailer = NULL;
    ass->trailer_size = 0;

    // Initialize dialogue to point near the middle to allow traversal
    dialogue = &dialogue_pool[DATA_SIZE / sizeof(DialogueLine) / 2];

    // Initialize loop pointers: cur starts at next, which is after dialogue
    next = dialogue->next;
    cur = next;
    prev = dialogue; // prev starts as current dialogue
}