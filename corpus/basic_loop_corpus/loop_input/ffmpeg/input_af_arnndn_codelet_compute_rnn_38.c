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

// Declare extern variables
RNNState *rnn;
float (*noise_input);

// Define data arrays
static float *generated_vad_gru_state;
static float *generated_noise_input;

// Initialization function
void init_vars() {
    // Allocate memory for model and state
    rnn = (RNNState*)calloc(1, sizeof(RNNState));
    rnn->model = (RNNModel*)calloc(1, sizeof(RNNModel));

    // Set sizes to achieve ~0.01 seconds runtime
    // Assume typical modern CPU can do ~1e9 iterations/sec
    // We want loop to run about 1e7 iterations for ~0.01 sec
    // But loop runs over vad_gru_size, so set it to ~1e7/2 = 5e6 to be safe
    rnn->model->input_dense_size = 1024;
    rnn->model->vad_gru_size = 8192;

    // Allocate states
    generated_vad_gru_state = (float*)calloc(rnn->model->vad_gru_size, sizeof(float));
    generated_noise_input = (float*)calloc(rnn->model->input_dense_size + rnn->model->vad_gru_size, sizeof(float));

    // Initialize pointers
    rnn->vad_gru_state = generated_vad_gru_state;
    noise_input = generated_noise_input;
}

// Finalize initialization after compilation
__attribute__((constructor))
void initialize() {
    init_vars();
}