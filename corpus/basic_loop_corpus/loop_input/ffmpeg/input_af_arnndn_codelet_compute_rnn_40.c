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

// External variables
RNNState *rnn;
float (*denoise_input);

// Static data buffers
static float *vad_gru_state_buffer;
static float *denoise_input_buffer;
static RNNModel model_instance;

void init_vars() {
    // Allocate approximately 64MB of data to achieve ~0.01s runtime
    // We'll set vad_gru_size to about 16M floats (64MB / 4 bytes per float / 4 arrays)
    const int size = 16 * 1024 * 1024; // 16 million elements

    // Allocate buffers
    vad_gru_state_buffer = (float*)calloc(size, sizeof(float));
    denoise_input_buffer = (float*)calloc(size, sizeof(float));
    
    if (!vad_gru_state_buffer || !denoise_input_buffer) {
        exit(1);
    }

    // Initialize model
    model_instance.vad_gru_size = size;

    // Initialize rnn state
    rnn = (RNNState*)malloc(sizeof(RNNState));
    if (!rnn) exit(1);
    
    rnn->vad_gru_state = vad_gru_state_buffer;
    rnn->model = &model_instance;

    // Initialize denoise_input pointer
    denoise_input = denoise_input_buffer;
}