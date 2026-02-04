#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DenseLayer {
    const float *bias;
    const float *input_weights;
    int nb_inputs;
    int nb_neurons;
    int activation;
} DenseLayer;

typedef struct GRULayer {
    const float *bias;
    const float *input_weights;
    const float *recurrent_weights;
    int nb_inputs;
    int nb_neurons;
    int activation;
} GRULayer;

typedef struct RNNModel {
    int input_dense_size;
    const DenseLayer *input_dense;
    int vad_gru_size;
    const GRULayer *vad_gru;
    int noise_gru_size;
    const GRULayer *noise_gru;
    int denoise_gru_size;
    const GRULayer *denoise_gru;
    int denoise_output_size;
    const DenseLayer *denoise_output;
    int vad_output_size;
    const DenseLayer *vad_output;
} RNNModel;

typedef struct RNNState {
    float *vad_gru_state;
    float *noise_gru_state;
    float *denoise_gru_state;
    RNNModel *model;
} RNNState;

typedef struct AVTXContext AVTXContext;

typedef void (*av_tx_fn)(AVTXContext *, void *, void *, ptrdiff_t);

typedef struct DenoiseState {
    float analysis_mem[480];
    float cepstral_mem[8][22];
    int memid;
    float synthesis_mem[480] __attribute__((aligned(32)));
    float pitch_buf[1728];
    float pitch_enh_buf[1728];
    float last_gain;
    int last_period;
    float mem_hp_x[2];
    float lastg[22];
    RNNState rnn;
    AVTXContext *tx;
    AVTXContext *txi;
    av_tx_fn tx_fn;
    av_tx_fn txi_fn;
} DenoiseState;

float g[22];
DenoiseState *st;

static DenseLayer s_input_dense;
static DenseLayer s_denoise_output;
static DenseLayer s_vad_output;
static GRULayer s_vad_gru;
static GRULayer s_noise_gru;
static GRULayer s_denoise_gru;
static RNNModel s_model;
static float s_vad_gru_state[256];
static float s_noise_gru_state[256];
static float s_denoise_gru_state[256];

void init_vars() {
    st = (DenoiseState*)calloc(1, sizeof(DenoiseState));
    if (!st) return;

    for (int i = 0; i < 22; i++) {
        g[i] = 0.5f;
        st->lastg[i] = 0.3f;
    }

    st->rnn.model = &s_model;
    st->rnn.vad_gru_state = s_vad_gru_state;
    st->rnn.noise_gru_state = s_noise_gru_state;
    st->rnn.denoise_gru_state = s_denoise_gru_state;

    s_model.input_dense_size = 1;
    s_model.input_dense = &s_input_dense;
    s_model.vad_gru_size = 1;
    s_model.vad_gru = &s_vad_gru;
    s_model.noise_gru_size = 1;
    s_model.noise_gru = &s_noise_gru;
    s_model.denoise_gru_size = 1;
    s_model.denoise_gru = &s_denoise_gru;
    s_model.denoise_output_size = 1;
    s_model.denoise_output = &s_denoise_output;
    s_model.vad_output_size = 1;
    s_model.vad_output = &s_vad_output;
}