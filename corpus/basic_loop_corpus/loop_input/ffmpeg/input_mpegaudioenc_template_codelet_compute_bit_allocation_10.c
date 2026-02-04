#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
int current_frame_size;
int incr;
unsigned char *alloc;

static unsigned char *internal_alloc_buffer;
static unsigned char *internal_table_buffer;

void init_vars() {
    internal_alloc_buffer = (unsigned char *)calloc(1, 262144);
    if (!internal_alloc_buffer) exit(1);

    internal_table_buffer = (unsigned char *)calloc(1, 262144);
    if (!internal_table_buffer) exit(1);

    s = (MpegAudioContext *)calloc(1, sizeof(MpegAudioContext));
    if (!s) exit(1);

    s->nb_channels = 2;
    s->sblimit = 32;

    s->alloc_table = internal_table_buffer;
    alloc = internal_alloc_buffer;

    for (int idx = 0; idx < 262144; idx++) {
        internal_alloc_buffer[idx] = rand() % 4;
    }

    for (int idx = 0; idx < 262144; idx++) {
        internal_table_buffer[idx] = rand() % 256;
    }

    current_frame_size = 0;
}

void loop(); 

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}