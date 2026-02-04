#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,
    AV_SAMPLE_FMT_S16,
    AV_SAMPLE_FMT_S32,
    AV_SAMPLE_FMT_FLT,
    AV_SAMPLE_FMT_DBL,
    AV_SAMPLE_FMT_U8P,
    AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P,
    AV_SAMPLE_FMT_FLTP,
    AV_SAMPLE_FMT_DBLP,
    AV_SAMPLE_FMT_S64,
    AV_SAMPLE_FMT_S64P,
    AV_SAMPLE_FMT_NB
};

typedef struct AudioData {
    uint8_t *ch[64];
    uint8_t *data;
    int ch_count;
    int bps;
    int count;
    int planar;
    enum AVSampleFormat fmt;
} AudioData;

AudioData *in;
int ch;
int planes;
unsigned int m;

static uint8_t *buffer_pool[64];
static AudioData audio_data_instance;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB to ensure sufficient runtime
    uint8_t *shared_data = (uint8_t *)calloc(total_data_size, 1);
    
    if (!shared_data) exit(1);

    in = &audio_data_instance;
    in->data = shared_data;
    in->ch_count = 64;
    in->bps = 4;
    in->count = 16 * 1024 * 1024;
    in->planar = 1;
    in->fmt = AV_SAMPLE_FMT_FLTP;

    planes = 64;
    ch = 0;
    m = 0;

    size_t chunk_size = total_data_size / 64;
    for (int i = 0; i < 64; i++) {
        buffer_pool[i] = shared_data + i * chunk_size;
        in->ch[i] = buffer_pool[i];
    }
}