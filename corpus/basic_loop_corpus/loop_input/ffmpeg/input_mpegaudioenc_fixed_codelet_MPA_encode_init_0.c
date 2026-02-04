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

const uint16_t avpriv_mpa_freq_tab[3] = { 44100, 22050, 11025 };

MpegAudioContext *s;
int freq;
int i;

void init_vars() {
    // Allocate and initialize the MpegAudioContext structure
    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);

    // Initialize pointers inside PutBitContext
    size_t buf_size = 1 << 20; // ~1MB buffer to ensure loop runs for desired duration
    s->pb.buf = (uint8_t *)malloc(buf_size);
    if (!s->pb.buf) exit(1);
    s->pb.buf_ptr = s->pb.buf;
    s->pb.buf_end = s->pb.buf + buf_size;
    s->pb.bit_buf = 0;
    s->pb.bit_left = 32;
    s->pb.size_in_bits = 0;

    // Set valid default values
    s->nb_channels = 2;
    s->lsf = 0;
    s->bitrate_index = 1;
    s->freq_index = 0;
    s->frame_size = 0;
    s->frame_frac = 0;
    s->frame_frac_incr = 1;
    s->do_padding = 0;
    s->sblimit = 32;

    // Initialize tables with dummy data
    for (int j = 0; j < 64; j++) {
        s->scale_factor_table[j] = j;
        s->scale_factor_shift[j] = (int8_t)(j % 3);
        s->scale_factor_mult[j] = (unsigned short)(j * 2);
    }
    for (int j = 0; j < 128; j++) {
        s->scale_diff_table[j] = (unsigned char)(j % 16);
    }
    for (int j = 0; j < 17; j++) {
        s->total_quant_bits[j] = (unsigned short)(j * 100);
    }

    // Set frequency to match one of the halved values in avpriv_mpa_freq_tab
    // This ensures the second condition triggers after two iterations
    freq = 11025; // which is avpriv_mpa_freq_tab[2] / 2 -> so loop runs 3 times
}