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
extern float (*dense_out);
extern float (*noise_input);

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by factor of 4
    int size = rnn->model->input_dense_size;
    int i = 0;
    
    // Unroll by 4 for consecutive access optimization
    for (; i <= size - 4; i += 4) {
        noise_input[i]     = dense_out[i];
        noise_input[i + 1] = dense_out[i + 1];
        noise_input[i + 2] = dense_out[i + 2];
        noise_input[i + 3] = dense_out[i + 3];
    }
    
    // Handle remaining elements
    for (; i < size; i++) {
        noise_input[i] = dense_out[i];
    }
}
