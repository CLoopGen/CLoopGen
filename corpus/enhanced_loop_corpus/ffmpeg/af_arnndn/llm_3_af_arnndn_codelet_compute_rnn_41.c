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

extern RNNState *rnn;
extern float (*denoise_input);

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride (simulating potential padding or interleaved data layout)
    int stride = 2;
    int offset = rnn->model->vad_gru_size;
    int size = rnn->model->noise_gru_size;
    for (int i = 0; i < size; i += stride) {
        // Ensure we don't exceed bounds on last iteration
        if (i + 0 < size) denoise_input[offset + i + 0] = rnn->noise_gru_state[i + 0];
        if (i + 1 < size) denoise_input[offset + i + 1] = rnn->noise_gru_state[i + 1];
    }
}
