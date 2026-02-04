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
extern uint8_t * *ssrc;
extern uint8_t **ddst;
extern int nb_samples;
extern int channels;
extern int i;
extern int c;
extern int delay_pos;
extern int modulation_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c < channels; c += 2) {
    if (c + 1 >= channels) break;
    int16_t *src0 = (int16_t *)ssrc[c];
    int16_t *src1 = (int16_t *)ssrc[c+1];
    int16_t *dst0 = (int16_t *)ddst[c];
    int16_t *dst1 = (int16_t *)ddst[c+1];
    double *buffer0 = s->delay_buffer + c * s->delay_buffer_length;
    double *buffer1 = s->delay_buffer + (c+1) * s->delay_buffer_length;
    int dpos0 = s->delay_pos;
    int dpos1 = s->delay_pos;
    int mpos0 = s->modulation_pos;
    int mpos1 = s->modulation_pos;

    for (i = 0; i < nb_samples; i++) {
        int idx0 = (dpos0 + s->modulation_buffer[mpos0]) % s->delay_buffer_length;
        int idx1 = (dpos1 + s->modulation_buffer[mpos1]) % s->delay_buffer_length;
        double v0 = (*src0++ * s->in_gain) + (buffer0[idx0] * s->decay);
        double v1 = (*src1++ * s->in_gain) + (buffer1[idx1] * s->decay);

        dpos0 = (dpos0 + 1) % s->delay_buffer_length;
        dpos1 = (dpos1 + 1) % s->delay_buffer_length;
        mpos0 = (mpos0 + 1) % s->modulation_buffer_length;
        mpos1 = (mpos1 + 1) % s->modulation_buffer_length;

        buffer0[dpos0] = v0;
        buffer1[dpos1] = v1;

        *dst0++ = (int16_t)(v0 * s->out_gain);
        *dst1++ = (int16_t)(v1 * s->out_gain);
    }
}
}
