#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef enum {
    I_F_Q = -1,
    SILENCE,
    RATE_OCTAVE,
    RATE_QUARTER,
    RATE_HALF,
    RATE_FULL
} qcelp_packet_rate;

typedef struct QCELPFrame {
    uint8_t cbsign[16];
    uint8_t cbgain[16];
    uint8_t cindex[16];
    uint8_t plag[4];
    uint8_t pfrac[4];
    uint8_t pgain[4];
    uint8_t lspv[10];
    uint8_t reserved;
} QCELPFrame;

typedef struct QCELPContext {
    GetBitContext gb;
    qcelp_packet_rate bitrate;
    QCELPFrame frame;
    uint8_t erasure_count;
    uint8_t octave_count;
    float prev_lspf[10];
    float predictor_lspf[10];
    float pitch_synthesis_filter_mem[303];
    float pitch_pre_filter_mem[303];
    float rnd_fir_filter_mem[180];
    float formant_mem[170];
    float last_codebook_gain;
    int prev_g1[2];
    int prev_bitrate;
    float pitch_gain[4];
    uint8_t pitch_lag[4];
    uint16_t first16bits;
    uint8_t warned_buf_mismatch_bitrate;
    float postfilter_synth_mem[10];
    float postfilter_agc_mem;
    float postfilter_tilt_mem;
} QCELPContext;

int8_t qcelp_rate_half_codebook[128] = {0};

QCELPContext *q;
float *gain;
float *cdn_vector;
int i;
int j;
uint16_t cindex;
float tmp_gain;

void init_vars() {
    q = (QCELPContext*)calloc(1, sizeof(QCELPContext));
    if (!q) exit(1);

    gain = (float*)malloc(4 * sizeof(float));
    if (!gain) exit(1);
    for (int idx = 0; idx < 4; idx++) {
        gain[idx] = 1.0f + idx * 0.1f;
    }

    const size_t cdn_size = 1 << 24; // ~16MB to target ~0.01s runtime
    cdn_vector = (float*)malloc(cdn_size * sizeof(float));
    if (!cdn_vector) exit(1);

    for (int idx = 0; idx < 16; idx++) {
        q->frame.cindex[idx] = idx * 8; 
    }

    for (int idx = 0; idx < 128; idx++) {
        qcelp_rate_half_codebook[idx] = (int8_t)(idx % 256 - 128);
    }
}