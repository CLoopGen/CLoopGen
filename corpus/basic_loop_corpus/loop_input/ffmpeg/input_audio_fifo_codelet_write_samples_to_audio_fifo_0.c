#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVFifoBuffer {
    uint8_t *buffer;
    uint8_t *rptr;
    uint8_t *wptr;
    uint8_t *end;
    uint32_t rndx;
    uint32_t wndx;
} AVFifoBuffer;

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

struct AVAudioFifo {
    AVFifoBuffer **buf;
    int nb_buffers;
    int nb_samples;
    int allocated_samples;
    int channels;
    enum AVSampleFormat sample_fmt;
    int sample_size;
};

typedef struct AVAudioFifo AVAudioFifo;

typedef struct TestStruct {
    const enum AVSampleFormat format;
    const int nb_ch;
    const void *data_planes[32];
    const int nb_samples_pch;
} TestStruct;

AVAudioFifo *afifo;
TestStruct *test_sample;
int offset_size;
int i;
void *data_planes[32];

static uint8_t *simulated_data_storage;
static AVFifoBuffer **simulated_buf_array;
static const enum AVSampleFormat test_format = AV_SAMPLE_FMT_S32P;
static const int test_nb_ch = 8;
static const int test_nb_samples_pch = 65536;
static const void *test_data_planes_init[32] = {0};

void init_vars() {
    const int total_data_size = 8 * 65536 * sizeof(float); // ~2MB data for 8 channels

    simulated_data_storage = (uint8_t *)calloc(total_data_size, 1);
    if (!simulated_data_storage) exit(1);

    for (int ch = 0; ch < test_nb_ch; ++ch) {
        ((void **)test_data_planes_init)[ch] = simulated_data_storage + ch * 65536 * sizeof(float);
    }

    test_sample = (TestStruct *)&(const TestStruct){
        .format = test_format,
        .nb_ch = test_nb_ch,
        .data_planes = { [0 ... 31] = 0 },
        .nb_samples_pch = test_nb_samples_pch
    };

    *(void **)(&((char **)test_sample)[offsetof(TestStruct, data_planes) / sizeof(char *)]) = (void *)test_data_planes_init;

    afifo = (AVAudioFifo *)calloc(1, sizeof(AVAudioFifo));
    if (!afifo) exit(1);

    afifo->nb_buffers = test_nb_ch;
    afifo->channels = test_nb_ch;
    afifo->sample_fmt = test_format;
    afifo->sample_size = sizeof(float);
    afifo->nb_samples = test_nb_samples_pch;
    afifo->allocated_samples = test_nb_samples_pch;

    simulated_buf_array = (AVFifoBuffer **)calloc(afifo->nb_buffers, sizeof(AVFifoBuffer *));
    if (!simulated_buf_array) exit(1);
    afifo->buf = simulated_buf_array;

    for (int i = 0; i < afifo->nb_buffers; ++i) {
        simulated_buf_array[i] = (AVFifoBuffer *)calloc(1, sizeof(AVFifoBuffer));
        if (!simulated_buf_array[i]) exit(1);
    }

    offset_size = 1024;
}