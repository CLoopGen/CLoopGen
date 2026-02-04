#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef uint16_t qcelp_vector[2];

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

qcelp_vector * qcelp_lspvq[5];
QCELPContext *q;
float *lspf;
int i;
float tmp_lspf;

void init_vars() {
    q = (QCELPContext*)calloc(1, sizeof(QCELPContext));
    if (!q) exit(1);

    lspf = (float*)calloc(10, sizeof(float));
    if (!lspf) exit(1);

    for (int idx = 0; idx < 5; idx++) {
        qcelp_lspvq[idx] = (qcelp_vector*)calloc(256, sizeof(qcelp_vector));
        if (!qcelp_lspvq[idx]) exit(1);
        for (int j = 0; j < 256; j++) {
            qcelp_lspvq[idx][j][0] = (uint16_t)(j * 123);
            qcelp_lspvq[idx][j][1] = (uint16_t)(j * 456);
        }
    }

    for (int idx = 0; idx < 10; idx++) {
        q->frame.lspv[idx] = (uint8_t)(idx * 20);
    }

    tmp_lspf = 0.001f;
}

static void __attribute__((constructor)) initialize() {
    init_vars();
}