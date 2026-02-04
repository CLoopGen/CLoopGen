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

DenoiseState *st;
float spec_variability;

static float bias_data[100];
static float input_weights_data[1000];
static float recurrent_weights_data[1000];
static float vad_gru_state_data[100];
static float noise_gru_state_data[100];
static float denoise_gru_state_data[100];

static DenseLayer input_dense;
static GRULayer vad_gru;
static GRULayer noise_gru;
static GRULayer denoise_gru;
static DenseLayer denoise_output;
static DenseLayer vad_output;
static RNNModel model;

void init_vars() {
    st = (DenoiseState*)calloc(1, sizeof(DenoiseState));
    if (!st) return;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 22; j++) {
            st->cepstral_mem[i][j] = (float)((i + j) % 100) * 0.1f;
        }
    }

    st->memid = 0;
    st->last_gain = 0.5f;
    st->last_period = 100;
    st->mem_hp_x[0] = 0.0f;
    st->mem_hp_x[1] = 0.0f;
    for (int i = 0; i < 22; i++) {
        st->lastg[i] = 0.1f * i;
    }

    spec_variability = 0.0f;

    st->rnn.vad_gru_state = vad_gru_state_data;
    st->rnn.noise_gru_state = noise_gru_state_data;
    st->rnn.denoise_gru_state = denoise_gru_state_data;
    st->rnn.model = &model;

    model.input_dense_size = 1;
    model.input_dense = &input_dense;
    model.vad_gru_size = 1;
    model.vad_gru = &vad_gru;
    model.noise_gru_size = 1;
    model.noise_gru = &noise_gru;
    model.denoise_gru_size = 1;
    model.denoise_gru = &denoise_gru;
    model.denoise_output_size = 1;
    model.denoise_output = &denoise_output;
    model.vad_output_size = 1;
    model.vad_output = &vad_output;

    input_dense.bias = bias_data;
    input_dense.input_weights = input_weights_data;
    input_dense.nb_inputs = 10;
    input_dense.nb_neurons = 10;
    input_dense.activation = 1;

    vad_gru.bias = bias_data;
    vad_gru.input_weights = input_weights_data;
    vad_gru.recurrent_weights = recurrent_weights_data;
    vad_gru.nb_inputs = 10;
    vad_gru.nb_neurons = 10;
    vad_gru.activation = 1;

    noise_gru.bias = bias_data;
    noise_gru.input_weights = input_weights_data;
    noise_gru.recurrent_weights = recurrent_weights_data;
    noise_gru.nb_inputs = 10;
    noise_gru.nb_neurons = 10;
    noise_gru.activation = 1;

    denoise_gru.bias = bias_data;
    denoise_gru.input_weights = input_weights_data;
    denoise_gru.recurrent_weights = recurrent_weights_data;
    denoise_gru.nb_inputs = 10;
    denoise_gru.nb_neurons = 10;
    denoise_gru.activation = 1;

    denoise_output.bias = bias_data;
    denoise_output.input_weights = input_weights_data;
    denoise_output.nb_inputs = 10;
    denoise_output.nb_neurons = 10;
    denoise_output.activation = 1;

    vad_output.bias = bias_data;
    vad_output.input_weights = input_weights_data;
    vad_output.nb_inputs = 10;
    vad_output.nb_neurons = 10;
    vad_output.activation = 1;

    st->tx = NULL;
    st->txi = NULL;
    st->tx_fn = NULL;
    st->txi_fn = NULL;
}