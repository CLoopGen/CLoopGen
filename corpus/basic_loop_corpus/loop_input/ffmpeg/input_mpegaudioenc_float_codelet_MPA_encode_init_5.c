#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PutBitContext {
    uint32_t bit_buf;
    int bit_left;
    uint8_t *buf;
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    int size_in_bits;
} PutBitContext;

typedef struct MpegAudioContext {
    PutBitContext pb;
    int nb_channels;
    int lsf;
    int bitrate_index;
    int freq_index;
    int frame_size;
    int frame_frac;
    int frame_frac_incr;
    int do_padding;
    short samples_buf[2][4096];
    int samples_offset[2];
    int sb_samples[2][3][12][32];
    unsigned char scale_factors[2][32][3];
    unsigned char scale_code[2][32];
    int sblimit;
    const unsigned char *alloc_table;
    int16_t filter_bank[512];
    int scale_factor_table[64];
    unsigned char scale_diff_table[128];
    float scale_factor_inv_table[64];
    unsigned short total_quant_bits[17];
} MpegAudioContext;

const int ff_mpa_quant_bits[17] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
};

MpegAudioContext *s;
int i;
int v;

void init_vars() {
    s = (MpegAudioContext*)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);
    s->pb.buf = (uint8_t*)calloc(1, 1024 * 1024);
    if (!s->pb.buf) exit(1);
    s->pb.buf_end = s->pb.buf + 1024 * 1024;
    s->pb.buf_ptr = s->pb.buf;
    s->nb_channels = 2;
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 2;
    s->frame_size = 1024;
    s->frame_frac = 0;
    s->frame_frac_incr = 100;
    s->do_padding = 0;
    s->sblimit = 32;
    s->alloc_table = (const unsigned char *)calloc(1, 256);
    if (!s->alloc_table) exit(1);
    for (int j = 0; j < 512; j++)
        s->filter_bank[j] = (int16_t)(j % 256);
    for (int j = 0; j < 64; j++)
        s->scale_factor_table[j] = j * 4;
    for (int j = 0; j < 128; j++)
        s->scale_diff_table[j] = (unsigned char)(j % 16);
    for (int j = 0; j < 64; j++)
        s->scale_factor_inv_table[j] = 1.0f / (j + 1);
    for (int j = 0; j < 17; j++)
        s->total_quant_bits[j] = 0;
}