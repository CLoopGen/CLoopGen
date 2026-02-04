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

int16_t qcelp_rate_full_codebook[128];
QCELPContext *q;
float *gain;
float *cdn_vector;
int i;
int j;
uint16_t cindex;
float tmp_gain;

void init_vars() {
    // Allocate and initialize the large codebook to ensure sufficient data size
    for (int idx = 0; idx < 128; idx++) {
        qcelp_rate_full_codebook[idx] = (int16_t)(idx * 256);
    }

    // Allocate QCELPContext instance
    q = (QCELPContext*)calloc(1, sizeof(QCELPContext));
    if (!q) exit(1);

    // Initialize frame.cindex values to valid indices (0-127), negated in loop
    for (int idx = 0; idx < 16; idx++) {
        q->frame.cindex[idx] = (uint8_t)(idx * 5); // ensures cindex after negation is negative
    }

    // Allocate gain array (16 elements as used in loop)
    gain = (float*)malloc(16 * sizeof(float));
    if (!gain) exit(1);
    for (int idx = 0; idx < 16; idx++) {
        gain[idx] = 1.0f + idx * 0.1f;
    }

    // Allocate cdn_vector with large size to meet runtime target (~0.01 sec)
    // The inner loop runs 16 * 10 = 160 iterations per outer iteration.
    // To get ~0.01s runtime on modern CPU (~1e9 ops/sec), aim for ~1e7 total operations.
    // So we scale outer loop count accordingly: let's set total cdn_vector size to 16 * 10 * N
    // We choose N such that total memory is around 64MB to ensure runtime.
    const size_t num_blocks = 400000;  // 400k blocks of 16 -> 400k*16*10 = 64M floats
    cdn_vector = (float*)malloc(num_blocks * 16 * 10 * sizeof(float));
    if (!cdn_vector) exit(1);

    // Initialize working variables
    i = 0;
    j = 0;
    cindex = 0;
    tmp_gain = 0.0f;
}