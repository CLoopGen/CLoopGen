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

const uint16_t avpriv_mpa_freq_tab[3] = { 44100, 22050, 11025 };

MpegAudioContext *s;
int freq;
int i;

void init_vars() {
    freq = 22050;

    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) return;

    s->lsf = 0;
    s->nb_channels = 2;
    s->bitrate_index = 1;
    s->freq_index = 1;
    s->frame_size = 0;
    s->frame_frac = 0;
    s->frame_frac_incr = 1;
    s->do_padding = 0;
    s->sblimit = 32;

    for (int ch = 0; ch < 2; ch++) {
        s->samples_offset[ch] = 0;
        for (int j = 0; j < 4096; j++) {
            s->samples_buf[ch][j] = 0;
        }
        for (int b = 0; b < 3; b++) {
            for (int k = 0; k < 12; k++) {
                for (int l = 0; l < 32; l++) {
                    s->sb_samples[ch][b][k][l] = 0;
                }
            }
            for (int m = 0; m < 3; m++) {
                s->scale_factors[ch][31][m] = 0;
            }
            s->scale_code[ch][31] = 0;
        }
    }

    for (int n = 0; n < 512; n++) {
        s->filter_bank[n] = 0;
    }
    for (int n = 0; n < 64; n++) {
        s->scale_factor_table[n] = n * 2;
        s->scale_factor_inv_table[n] = 1.0f / (n + 1);
    }
    for (int n = 0; n < 128; n++) {
        s->scale_diff_table[n] = n % 16;
    }
    for (int n = 0; n < 17; n++) {
        s->total_quant_bits[n] = n * 100;
    }

    s->pb.buf = (uint8_t *)malloc(1024 * 1024);
    if (s->pb.buf) {
        s->pb.buf_ptr = s->pb.buf;
        s->pb.buf_end = s->pb.buf + 1024 * 1024;
        s->pb.bit_buf = 0;
        s->pb.bit_left = 32;
        s->pb.size_in_bits = 0;
    }

    const unsigned char *alloc_ptr = (const unsigned char *)malloc(256);
    if (alloc_ptr) {
        for (int idx = 0; idx < 256; idx++) {
            ((unsigned char *)alloc_ptr)[idx] = idx % 64;
        }
    }
    s->alloc_table = alloc_ptr;
}