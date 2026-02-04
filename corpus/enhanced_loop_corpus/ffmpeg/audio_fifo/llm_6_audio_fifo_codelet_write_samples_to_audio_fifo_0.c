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

extern AVAudioFifo *afifo;
extern  TestStruct *test_sample;
extern int offset_size;
extern int i;
extern void *data_planes[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **temp_planes = (uint8_t **)data_planes;
    for (i = 0; i < afifo->nb_buffers; ++i) {
        temp_planes[i] = (uint8_t *)test_sample->data_planes[i] + offset_size;
    }
}
