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

float fixed_smr[32];
MpegAudioContext *s;
short smr[32];
int i;

void init_vars() {
    for (int j = 0; j < 32; j++) {
        fixed_smr[j] = 1.5f + j * 0.1f;
        smr[j] = 0;
    }

    s = (MpegAudioContext*)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);

    s->sblimit = 32;

    s->pb.buf = (uint8_t*)malloc(1024);
    if (!s->pb.buf) exit(1);
    s->pb.buf_ptr = s->pb.buf;
    s->pb.buf_end = s->pb.buf + 1024;
    s->pb.bit_left = 32;

    static unsigned char dummy_alloc_table[16] = {0};
    s->alloc_table = dummy_alloc_table;

    for (int j = 0; j < 512; j++) {
        s->filter_bank[j] = (int16_t)(j % 256);
    }
    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j * 2;
        s->scale_factor_shift[j] = (int8_t)(j % 7);
        s->scale_factor_mult[j] = (unsigned short)(j * 3);
    }
    for (int j = 0; j < 128; j++) {
        s->scale_diff_table[j] = (unsigned char)(j % 16);
    }
    for (int j = 0; j < 17; j++) {
        s->total_quant_bits[j] = (unsigned short)((j + 1) * 100);
    }
    for (int ch = 0; ch < 2; ch++) {
        for (int sb = 0; sb < 32; sb++) {
            s->scale_code[ch][sb] = (unsigned char)((sb + ch) % 16);
            for (int sfb = 0; sfb < 3; sfb++) {
                s->scale_factors[ch][sb][sfb] = (unsigned char)((sb + sfb) % 16);
            }
        }
        s->samples_offset[ch] = 0;
        for (int k = 0; k < 4096; k++) {
            s->samples_buf[ch][k] = (short)(k % 32768);
        }
    }
    for (int ch = 0; ch < 2; ch++) {
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < 12; c++) {
                for (int d = 0; d < 32; d++) {
                    s->sb_samples[ch][b][c][d] = (ch + b + c + d) % 1000;
                }
            }
        }
    }
}