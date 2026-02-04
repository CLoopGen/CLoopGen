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

extern AudioPhaserContext *s;
extern uint8_t **ssrc;
extern uint8_t **ddst;
extern int nb_samples;
extern int channels;
extern int i;
extern int c;
extern int delay_pos;
extern int modulation_pos;

static AudioPhaserContext audio_phaser_ctx;
static AVClass av_class;
static double *delay_buffer;
static int32_t *modulation_buffer;
static uint8_t **src_buffers;
static uint8_t **dst_buffers;
static float *raw_src_data;
static float *raw_dst_data;

void init_vars() {
    channels = 2;
    nb_samples = 1 << 18; // ~262k samples per channel -> total data ~2MB float input, suitable for ~0.01s runtime

    audio_phaser_ctx.delay_buffer_length = 1 << 16;
    audio_phaser_ctx.modulation_buffer_length = 1 << 12;

    audio_phaser_ctx.in_gain = 0.8;
    audio_phaser_ctx.out_gain = 0.7;
    audio_phaser_ctx.decay = 0.3;
    audio_phaser_ctx.speed = 0.5;
    audio_phaser_ctx.type = 0;
    audio_phaser_ctx.delay_pos = 0;
    audio_phaser_ctx.modulation_pos = 0;
    audio_phaser_ctx.phaser = NULL;

    delay_buffer = calloc(audio_phaser_ctx.delay_buffer_length * channels, sizeof(double));
    modulation_buffer = malloc(audio_phaser_ctx.modulation_buffer_length * sizeof(int32_t));

    for (int i = 0; i < audio_phaser_ctx.modulation_buffer_length; i++) {
        modulation_buffer[i] = i % (audio_phaser_ctx.delay_buffer_length / 2);
    }

    raw_src_data = malloc(nb_samples * channels * sizeof(float));
    raw_dst_data = malloc(nb_samples * channels * sizeof(float));

    src_buffers = malloc(channels * sizeof(uint8_t *));
    dst_buffers = malloc(channels * sizeof(uint8_t *));

    for (int ch = 0; ch < channels; ch++) {
        src_buffers[ch] = (uint8_t *)&raw_src_data[ch * nb_samples];
        dst_buffers[ch] = (uint8_t *)&raw_dst_data[ch * nb_samples];
    }

    audio_phaser_ctx.delay_buffer = delay_buffer;
    audio_phaser_ctx.modulation_buffer = modulation_buffer;

    s = &audio_phaser_ctx;
    ssrc = src_buffers;
    ddst = dst_buffers;
}

AudioPhaserContext *s = &audio_phaser_ctx;
uint8_t **ssrc = NULL;
uint8_t **ddst = NULL;
int nb_samples = 0;
int channels = 0;
int i = 0;
int c = 0;
int delay_pos = 0;
int modulation_pos = 0;