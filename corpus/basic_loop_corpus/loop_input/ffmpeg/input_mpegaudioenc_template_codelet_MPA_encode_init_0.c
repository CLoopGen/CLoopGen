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

const uint16_t avpriv_mpa_freq_tab[3] = { 22050, 24000, 32000 };

MpegAudioContext *s;
int freq;
int i;

void init_vars() {
    // Allocate s on heap to avoid large stack usage
    s = (MpegAudioContext*)calloc(1, sizeof(MpegAudioContext));
    if (!s) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize pointers inside PutBitContext
    size_t buf_size = 1024 * 1024; // 1MB buffer
    s->pb.buf = (uint8_t*)malloc(buf_size);
    if (!s->pb.buf) {
        fprintf(stderr, "Buffer allocation failed\n");
        exit(1);
    }
    s->pb.buf_ptr = s->pb.buf;
    s->pb.buf_end = s->pb.buf + buf_size;
    s->pb.bit_buf = 0;
    s->pb.bit_left = 32;
    s->pb.size_in_bits = 0;

    // Set meaningful defaults
    s->nb_channels = 2;
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 1;
    s->frame_size = 1152;
    s->frame_frac = 0;
    s->frame_frac_incr = 1152;
    s->do_padding = 0;
    
    // Zero out arrays
    for (int ch = 0; ch < 2; ch++) {
        s->samples_offset[ch] = 0;
        for (int j = 0; j < 4096; j++) {
            s->samples_buf[ch][j] = 0;
        }
        for (int k = 0; k < 32; k++) {
            s->scale_code[ch][k] = 0;
            for (int m = 0; m < 3; m++) {
                s->scale_factors[ch][k][m] = 0;
            }
        }
        for (int b = 0; b < 3; b++) {
            for (int n = 0; n < 12; n++) {
                for (int p = 0; p < 32; p++) {
                    s->sb_samples[ch][b][n][p] = 0;
                }
            }
        }
    }

    s->sblimit = 32;
    
    // Allocate and initialize alloc_table if needed
    unsigned char* alloc_table_data = (unsigned char*)malloc(64);
    if (!alloc_table_data) {
        fprintf(stderr, "Alloc table allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx < 64; idx++) {
        alloc_table_data[idx] = idx % 16;
    }
    s->alloc_table = alloc_table_data;

    // Initialize other tables
    for (int idx = 0; idx < 512; idx++) {
        s->filter_bank[idx] = (int16_t)(idx % 256);
    }
    for (int idx = 0; idx < 64; idx++) {
        s->scale_factor_table[idx] = idx * 4;
        s->scale_factor_shift[idx] = (int8_t)(idx % 8);
        s->scale_factor_mult[idx] = (unsigned short)(idx * 5);
    }
    for (int idx = 0; idx < 128; idx++) {
        s->scale_diff_table[idx] = (unsigned char)(idx % 16);
    }
    for (int idx = 0; idx < 17; idx++) {
        s->total_quant_bits[idx] = (unsigned short)(idx * 100);
    }

    // Set freq to a value that will match one of the conditions in the loop
    freq = 24000; // This will match avpriv_mpa_freq_tab[1]
}