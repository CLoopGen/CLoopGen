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

typedef struct AudioPhaserContext {
    const AVClass *class;
    double in_gain;
    double out_gain;
    double delay;
    double decay;
    double speed;
    int type;
    int delay_buffer_length;
    double *delay_buffer;
    int modulation_buffer_length;
    int32_t *modulation_buffer;
    int delay_pos;
    int modulation_pos;
    void (*phaser)(struct AudioPhaserContext *, uint8_t *const *, uint8_t **, int, int);
} AudioPhaserContext;

static AVClass av_class_instance = { .class_name = "audio_phaser" };
static struct AVOption dummy_option = { .name = "dummy" };

static double *global_delay_buffer = NULL;
static int32_t *global_modulation_buffer = NULL;
static uint8_t **src_buffers = NULL;
static uint8_t **dst_buffers = NULL;

AudioPhaserContext *s;
uint8_t * *ssrc;
uint8_t **ddst;
int nb_samples;
int channels;
int i;
int c;
int delay_pos;
int modulation_pos;

void init_vars() {
    channels = 2; 
    nb_samples = 512 * 1024; 

    s = (AudioPhaserContext *)calloc(1, sizeof(AudioPhaserContext));
    if (!s) exit(1);

    s->class = &av_class_instance;
    s->in_gain = 1.0;
    s->out_gain = 0.8;
    s->decay = 0.7;
    s->speed = 0.5;
    s->type = 0;
    s->delay_buffer_length = 1024;
    s->modulation_buffer_length = 512;
    s->delay_pos = 0;
    s->modulation_pos = 0;

    global_delay_buffer = (double *)calloc(channels * s->delay_buffer_length, sizeof(double));
    if (!global_delay_buffer) exit(1);
    s->delay_buffer = global_delay_buffer;

    global_modulation_buffer = (int32_t *)malloc(s->modulation_buffer_length * sizeof(int32_t));
    if (!global_modulation_buffer) exit(1);
    for (int i = 0; i < s->modulation_buffer_length; i++) {
        global_modulation_buffer[i] = i % 128;
    }
    s->modulation_buffer = global_modulation_buffer;

    src_buffers = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    dst_buffers = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    if (!src_buffers || !dst_buffers) exit(1);

    size_t sample_size = nb_samples * sizeof(int32_t);
    for (int ch = 0; ch < channels; ch++) {
        src_buffers[ch] = (uint8_t *)malloc(sample_size);
        dst_buffers[ch] = (uint8_t *)calloc(nb_samples, sizeof(int32_t));
        if (!src_buffers[ch] || !dst_buffers[ch]) exit(1);
        for (int i = 0; i < nb_samples; i++) {
            ((int32_t *)src_buffers[ch])[i] = rand() % 65536 - 32768;
        }
    }

    ssrc = src_buffers;
    ddst = dst_buffers;
}