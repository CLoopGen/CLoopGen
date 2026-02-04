#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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

static float *input_data;
static float *denoise_input_data;
static DenseLayer input_dense_instance;
static GRULayer vad_gru_instance;
static GRULayer noise_gru_instance;
static GRULayer denoise_gru_instance;
static DenseLayer denoise_output_instance;
static RNNModel model_instance;
static RNNState state_instance;

RNNState *rnn = &state_instance;
float *input;
float (*denoise_input);

void init_vars() {
    const int data_size = 1 << 20;
    input_data = (float*)calloc(data_size, sizeof(float));
    denoise_input_data = (float*)calloc(data_size, sizeof(float));

    input = input_data;
    denoise_input = (float(*) )denoise_input_data;

    model_instance.vad_gru_size = 64;
    model_instance.noise_gru_size = 64;

    rnn->model = &model_instance;
}