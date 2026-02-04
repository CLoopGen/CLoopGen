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

MpegAudioContext *s;
int i;
int current_frame_size;
int incr;
unsigned char *alloc;

static unsigned char *internal_alloc_buffer = NULL;
static unsigned char *internal_alloc_table = NULL;

void init_vars() {
    internal_alloc_buffer = (unsigned char *)calloc(1, 131072);
    if (!internal_alloc_buffer) exit(1);

    internal_alloc_table = (unsigned char *)calloc(1, 65536);
    if (!internal_alloc_table) exit(1);

    for (int idx = 0; idx < 65536; ++idx) {
        internal_alloc_table[idx] = idx % 16;
    }

    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);

    s->nb_channels = 2;
    s->sblimit = 32;
    s->alloc_table = internal_alloc_table;

    alloc = internal_alloc_buffer;
    for (int idx = 0; idx < 32; ++idx) {
        internal_alloc_buffer[idx] = (idx % 4);
    }

    current_frame_size = 0;
    i = 0;
    incr = 0;
}