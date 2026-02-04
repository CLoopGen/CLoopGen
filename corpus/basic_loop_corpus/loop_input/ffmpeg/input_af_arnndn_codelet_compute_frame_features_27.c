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
float (*p);
int pitch_index = 0;

static float p_buffer[2 * (120 << 2)];
static DenseLayer input_dense;
static DenseLayer denoise_output;
static DenseLayer vad_output;
static GRULayer vad_gru;
static GRULayer noise_gru;
static GRULayer denoise_gru;
static RNNModel model;

void init_vars() {
    st = (DenoiseState *)calloc(1, sizeof(DenoiseState));
    p = p_buffer;

    for (int i = 0; i < 1728; i++) {
        st->pitch_buf[i] = (float)(i % 1000) / 1000.0f;
    }

    st->rnn.model = &model;

    model.input_dense = &input_dense;
    model.vad_gru = &vad_gru;
    model.noise_gru = &noise_gru;
    model.denoise_gru = &denoise_gru;
    model.denoise_output = &denoise_output;
    model.vad_output = &vad_output;

    pitch_index = 0;
}