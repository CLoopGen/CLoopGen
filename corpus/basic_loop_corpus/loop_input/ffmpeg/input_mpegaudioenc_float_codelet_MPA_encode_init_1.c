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

const uint16_t avpriv_mpa_bitrate_tab[2][3][15] = {
    { // lsf = 0
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384},
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320}
    },
    { // lsf = 1
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384},
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320}
    }
};

MpegAudioContext *s;
int bitrate = 128;
int i;

void init_vars() {
    s = malloc(sizeof(MpegAudioContext));
    if (!s) return;

    s->lsf = 0;
    s->pb.buf = malloc(1 << 20);
    s->pb.buf_end = s->pb.buf + (1 << 20);
    s->pb.buf_ptr = s->pb.buf;
    s->pb.bit_left = 32;
    s->pb.bit_buf = 0;
    s->pb.size_in_bits = 0;

    s->nb_channels = 2;
    s->bitrate_index = 0;
    s->freq_index = 0;
    s->frame_size = 0;
    s->frame_frac = 0;
    s->frame_frac_incr = 0;
    s->do_padding = 0;
    s->sblimit = 32;

    for (int ch = 0; ch < 2; ch++) {
        for (int j = 0; j < 4096; j++) {
            s->samples_buf[ch][j] = 0;
        }
        s->samples_offset[ch] = 0;
        for (int k = 0; k < 32; k++) {
            s->scale_code[ch][k] = 0;
            for (int l = 0; l < 3; l++) {
                s->scale_factors[ch][k][l] = 0;
            }
        }
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int b = 0; b < 3; b++) {
            for (int sbl = 0; sbl < 12; sbl++) {
                for (int sam = 0; sam < 32; sam++) {
                    s->sb_samples[ch][b][sbl][sam] = 0;
                }
            }
        }
    }

    for (int j = 0; j < 512; j++) {
        s->filter_bank[j] = 0;
    }
    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j;
        s->scale_factor_inv_table[j] = 1.0f / (j + 1);
    }
    for (int j = 0; j < 128; j++) {
        s->scale_diff_table[j] = j % 16;
    }
    for (int j = 0; j < 17; j++) {
        s->total_quant_bits[j] = j * 100;
    }

    static unsigned char dummy_alloc[100];
    s->alloc_table = dummy_alloc;
}