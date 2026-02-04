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
    RNNModel *model;
} RNNState;

static float *denoise_input_data;
static float *noise_gru_state_data;
static RNNModel model_instance;
static RNNState rnn_instance;

RNNState *rnn = &rnn_instance;
float (*denoise_input) = NULL;

void init_vars() {
    // Set sizes to achieve ~0.01s runtime: aim for moderate memory access (~10-50MB)
    // The loop copies noise_gru_size floats, so we set it to ~40 million elements for measurable time
    // But balance with typical use; here we choose 2 million for reasonable test size
    const int target_size = 2000000; // ~8MB of data

    model_instance.noise_gru_size = target_size;
    model_instance.vad_gru_size = 512; // arbitrary but realistic

    // Allocate state data
    noise_gru_state_data = (float*)calloc(target_size, sizeof(float));
    if (!noise_gru_state_data) exit(1);

    // Allocate denoise_input buffer (vad_gru_size + noise_gru_size)
    int total_denoise_input_size = model_instance.vad_gru_size + model_instance.noise_gru_size;
    denoise_input_data = (float*)calloc(total_denoise_input_size, sizeof(float));
    if (!denoise_input_data) exit(1);

    // Initialize pointers
    rnn_instance.noise_gru_state = noise_gru_state_data;
    rnn_instance.model = &model_instance;

    // Set denoise_input to point at the full buffer
    denoise_input = denoise_input_data;

    // Ensure all other model fields are initialized to avoid undefined behavior
    model_instance.input_dense_size = 0;
    model_instance.input_dense = NULL;
    model_instance.vad_gru = NULL;
    model_instance.denoise_gru = NULL;
    model_instance.denoise_output_size = 0;
    model_instance.denoise_output = NULL;
    model_instance.vad_output_size = 0;
    model_instance.vad_output = NULL;
}