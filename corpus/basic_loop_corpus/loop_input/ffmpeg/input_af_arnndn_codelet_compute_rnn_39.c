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

// External variables
RNNState *rnn;
float *input;
float *noise_input;

// Allocate sufficient data to make loop run ~0.01s (adjust array sizes accordingly)
#define NOISE_INPUT_SIZE (256 * 1024 * 1024) // ~1GB of float data (approx. 1s for large copies, scale down)
#define INPUT_SIZE 42

static float *input_data = NULL;
static float *noise_input_data = NULL;
static RNNModel *model_data = NULL;
static RNNState state;

void init_vars() {
    // Allocate input arrays
    input_data = (float*)calloc(INPUT_SIZE, sizeof(float));
    noise_input_data = (float*)calloc(NOISE_INPUT_SIZE, sizeof(float));
    
    // Initialize model data
    model_data = (RNNModel*)calloc(1, sizeof(RNNModel));
    model_data->input_dense_size = 0;
    model_data->vad_gru_size = 0;
    model_data->noise_gru_size = 100; // Ensure offset is valid: i + 0 + 100 <= NOISE_INPUT_SIZE
    model_data->denoise_gru_size = 0;
    model_data->denoise_output_size = 0;
    model_data->vad_output_size = 0;

    // Set external pointers
    input = input_data;
    noise_input = noise_input_data;
    rnn = &state;
    rnn->model = model_data;
    rnn->vad_gru_state = NULL;
    rnn->noise_gru_state = NULL;
    rnn->denoise_gru_state = NULL;

    // Pre-initialize input with non-zero values for realism
    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = (float)(i % 100) / 100.0f;
    }
}