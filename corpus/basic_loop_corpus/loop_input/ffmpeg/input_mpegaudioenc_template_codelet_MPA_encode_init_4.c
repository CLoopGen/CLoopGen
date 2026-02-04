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

MpegAudioContext *s;
int i;
int v;

void init_vars() {
    s = (MpegAudioContext*)calloc(1, sizeof(MpegAudioContext));
    if (!s) return;

    s->nb_channels = 2;
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 2;
    s->frame_size = 1024;
    s->frame_frac = 0;
    s->frame_frac_incr = 1;
    s->do_padding = 0;
    s->sblimit = 32;

    for (int ch = 0; ch < 2; ch++) {
        for (int b = 0; b < 3; b++) {
            for (int l = 0; l < 12; l++) {
                for (int samp = 0; samp < 32; samp++) {
                    s->sb_samples[ch][b][l][samp] = 0;
                }
            }
        }
        for (int j = 0; j < 32; j++) {
            s->scale_factors[ch][j][0] = 0;
            s->scale_factors[ch][j][1] = 0;
            s->scale_factors[ch][j][2] = 0;
            s->scale_code[ch][j] = 0;
        }
        s->samples_offset[ch] = 0;
    }

    for (int j = 0; j < 4096; j++) {
        s->samples_buf[0][j] = 0;
        s->samples_buf[1][j] = 0;
    }

    for (int j = 0; j < 512; j++) {
        s->filter_bank[j] = 0;
    }

    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j;
        s->scale_factor_shift[j] = 0;
        s->scale_factor_mult[j] = 1;
    }

    for (int j = 0; j < 17; j++) {
        s->total_quant_bits[j] = j * 100;
    }

    static unsigned char dummy_alloc_table[256];
    for (int j = 0; j < 256; j++) {
        dummy_alloc_table[j] = j % 17;
    }
    s->alloc_table = dummy_alloc_table;

    for (int j = 0; j < 128; j++) {
        s->scale_diff_table[j] = 0;
    }
}