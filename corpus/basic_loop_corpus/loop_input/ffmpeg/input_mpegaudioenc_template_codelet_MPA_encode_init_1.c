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
    int8_t scale_factor_shift[64];
    unsigned short scale_factor_mult[64];
    unsigned short total_quant_bits[17];
} MpegAudioContext;

const uint16_t avpriv_mpa_bitrate_tab[2][3][15] = {
    {
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160}
    },
    {
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160}
    }
};

MpegAudioContext *s;
int bitrate;
int i;

static unsigned char alloc_table_data[64];

void init_vars() {
    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) return;

    s->lsf = 0;
    bitrate = 96;

    for (int j = 0; j < 64; j++) {
        alloc_table_data[j] = j % 64;
    }
    s->alloc_table = alloc_table_data;

    s->sblimit = 32;
    s->nb_channels = 2;
    s->bitrate_index = 1;
    s->freq_index = 1;
    s->frame_size = 1024;
    s->frame_frac = 0;
    s->frame_frac_incr = 100;
    s->do_padding = 0;

    s->pb.bit_buf = 0;
    s->pb.bit_left = 32;
    s->pb.buf = (uint8_t *)malloc(2048);
    s->pb.buf_ptr = s->pb.buf;
    s->pb.buf_end = s->pb.buf + 2048;
    s->pb.size_in_bits = 0;

    for (int j = 0; j < 512; j++) {
        s->filter_bank[j] = j % 32768;
    }

    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j * 4;
        s->scale_factor_shift[j] = j % 128 > 64 ? -1 : 0;
        s->scale_factor_mult[j] = j * 2 + 1;
    }

    for (int j = 0; j < 128; j++) {
        s->scale_diff_table[j] = j % 64;
    }

    for (int j = 0; j < 17; j++) {
        s->total_quant_bits[j] = j * 100;
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int sf = 0; sf < 32; sf++) {
            s->scale_code[ch][sf] = sf % 16;
            for (int k = 0; k < 3; k++) {
                s->scale_factors[ch][sf][k] = (sf + k) % 64;
            }
        }
        s->samples_offset[ch] = 0;
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int i = 0; i < 4096; i++) {
            s->samples_buf[ch][i] = i % 32768;
        }
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int b = 0; b < 3; b++) {
            for (int sbl = 0; sbl < 12; sbl++) {
                for (int sam = 0; sam < 32; sam++) {
                    s->sb_samples[ch][b][sbl][sam] = (ch + b + sbl + sam) % 1024;
                }
            }
        }
    }
}