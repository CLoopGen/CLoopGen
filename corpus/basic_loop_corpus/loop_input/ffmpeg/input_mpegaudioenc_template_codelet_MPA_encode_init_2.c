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

static uint8_t internal_buf[1 << 20]; // 1MB buffer for pb.buf
static unsigned char alloc_table_data[256];

void init_vars() {
    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);

    s->nb_channels = 2;
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 2;
    s->frame_size = 3;
    s->frame_frac = 0;
    s->frame_frac_incr = 1;
    s->do_padding = 0;
    s->sblimit = 1;

    s->pb.buf = internal_buf;
    s->pb.buf_ptr = internal_buf;
    s->pb.buf_end = internal_buf + sizeof(internal_buf);
    s->pb.bit_buf = 0;
    s->pb.bit_left = 32;
    s->pb.size_in_bits = 0;

    s->alloc_table = alloc_table_data;

    for (int j = 0; j < 512; j++)
        s->filter_bank[j] = (int16_t)(j * 2);
    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j * 4;
        s->scale_factor_shift[j] = (int8_t)(j % 128 - 64);
        s->scale_factor_mult[j] = (unsigned short)(j * 3);
    }
    for (int j = 0; j < 128; j++)
        s->scale_diff_table[j] = (unsigned char)(j % 128);
    for (int j = 0; j < 17; j++)
        s->total_quant_bits[j] = (unsigned short)(j * 100);

    for (int j = 0; j < 2; j++) {
        s->samples_offset[j] = 4096; // initialize to non-zero so loop has effect
        for (int k = 0; k < 4096; k++)
            s->samples_buf[j][k] = (short)(k % 32768);
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 12; l++) {
                for (int m = 0; m < 32; m++)
                    s->sb_samples[j][k][l][m] = l * m;
            }
        }
        for (int k = 0; k < 32; k++) {
            for (int l = 0; l < 3; l++)
                s->scale_factors[j][k][l] = (unsigned char)((k + l) % 256);
            s->scale_code[j][k] = (unsigned char)(k % 256);
        }
    }

    for (int j = 0; j < 256; j++)
        alloc_table_data[j] = (unsigned char)(j % 256);
}