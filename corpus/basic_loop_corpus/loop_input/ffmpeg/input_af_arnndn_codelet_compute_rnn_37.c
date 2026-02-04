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

static float *generated_dense_out = NULL;
static float *generated_noise_input = NULL;
static DenseLayer static_input_dense;
static RNNModel model_instance;
static RNNState rnn_instance;

RNNState *rnn = &rnn_instance;
float (*dense_out) = NULL;
float (*noise_input) = NULL;

void init_vars() {
    const int data_size = 64 * 1024 * 1024 / sizeof(float); // ~256MB total for two arrays

    generated_dense_out = (float*)calloc(data_size, sizeof(float));
    generated_noise_input = (float*)calloc(data_size, sizeof(float));
    
    if (!generated_dense_out || !generated_noise_input) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < data_size; i++) {
        generated_dense_out[i] = (float)(i % 1000) / 100.0f;
    }

    dense_out = generated_dense_out;
    noise_input = generated_noise_input;

    static_input_dense.nb_inputs = data_size;
    static_input_dense.nb_neurons = 1;
    static_input_dense.bias = NULL;
    static_input_dense.input_weights = NULL;
    static_input_dense.activation = 0;

    model_instance.input_dense_size = data_size;
    model_instance.input_dense = &static_input_dense;
    model_instance.vad_gru_size = 0;
    model_instance.vad_gru = NULL;
    model_instance.noise_gru_size = 0;
    model_instance.noise_gru = NULL;
    model_instance.denoise_gru_size = 0;
    model_instance.denoise_gru = NULL;
    model_instance.denoise_output_size = 0;
    model_instance.denoise_output = NULL;
    model_instance.vad_output_size = 0;
    model_instance.vad_output = NULL;

    rnn_instance.model = &model_instance;
    rnn_instance.vad_gru_state = NULL;
    rnn_instance.noise_gru_state = NULL;
    rnn_instance.denoise_gru_state = NULL;
}