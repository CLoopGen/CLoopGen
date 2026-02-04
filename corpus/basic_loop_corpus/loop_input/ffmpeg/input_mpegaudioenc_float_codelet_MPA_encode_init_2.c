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

static uint8_t global_buf[1024 * 1024]; // 1MB buffer

static unsigned char static_alloc_table[256];

MpegAudioContext *s;
int i;

void init_vars() {
    // Allocate and initialize s
    s = (MpegAudioContext*)calloc(1, sizeof(MpegAudioContext));
    if (!s) return;

    // Initialize PutBitContext buffer pointers
    s->pb.buf = global_buf;
    s->pb.buf_ptr = global_buf;
    s->pb.buf_end = global_buf + sizeof(global_buf);
    s->pb.bit_buf = 0;
    s->pb.bit_left = 32;
    s->pb.size_in_bits = 0;

    // Set reasonable values for parameters
    s->nb_channels = 2;  // stereo
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 1;
    s->frame_size = 1152;
    s->frame_frac = 0;
    s->frame_frac_incr = 1152;
    s->do_padding = 0;
    s->sblimit = 32;

    // Initialize alloc_table as a valid pointer
    s->alloc_table = static_alloc_table;

    // Zero out arrays that are not fully initialized
    for (int ch = 0; ch < 2; ch++) {
        for (int j = 0; j < 4096; j++) {
            s->samples_buf[ch][j] = 0;
        }
        s->samples_offset[ch] = 0;
        for (int j = 0; j < 32; j++) {
            s->scale_code[ch][j] = 0;
            for (int k = 0; k < 3; k++) {
                s->scale_factors[ch][j][k] = 0;
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 12; k++) {
                for (int l = 0; l < 32; l++) {
                    s->sb_samples[ch][j][k][l] = 0;
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

    // Initialize alloc_table data
    for (int j = 0; j < 256; j++) {
        static_alloc_table[j] = j % 16;
    }

    // Ensure loop bounds are safe: nb_channels <= 2 to match array size of samples_offset
    if (s->nb_channels > 2) {
        s->nb_channels = 2;
    }
}