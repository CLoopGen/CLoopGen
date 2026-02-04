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
extern int nb_samples;
extern int channels;
extern int i;
extern int c;
extern int delay_pos;
extern int modulation_pos;
extern double *src;
extern double *dst;
extern double *buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nb_samples; i++) {
    int base_delay = delay_pos + s->modulation_buffer[modulation_pos];
    int pos = (base_delay >= s->delay_buffer_length) ? base_delay - s->delay_buffer_length : base_delay;
    pos *= channels;
    int npos = (((delay_pos + 1) >= s->delay_buffer_length) ? (delay_pos + 1) - s->delay_buffer_length : (delay_pos + 1)) * channels;
    
    // Consecutive memory access: preload channel data into local arrays to promote contiguous access
    double src_cache[8], dst_cache[8], buf_cache[8], out_cache[8];
    for (c = 0; c < channels; c++) {
        src_cache[c] = src[c];
        buf_cache[c] = buffer[pos + c];
    }
    
    for (c = 0; c < channels; c++) {
        double v = src_cache[c] * s->in_gain + buf_cache[c] * s->decay;
        buffer[npos + c] = v;
        out_cache[c] = v * s->out_gain;
    }
    
    // Write back consecutively
    for (c = 0; c < channels; c++) {
        dst[c] = out_cache[c];
    }

    src += channels;
    dst += channels;
    delay_pos = (((delay_pos + 1) >= s->delay_buffer_length) ? (delay_pos + 1) - s->delay_buffer_length : (delay_pos + 1));
    modulation_pos = (((modulation_pos + 1) >= s->modulation_buffer_length) ? (modulation_pos + 1) - s->modulation_buffer_length : (modulation_pos + 1));
}
}
