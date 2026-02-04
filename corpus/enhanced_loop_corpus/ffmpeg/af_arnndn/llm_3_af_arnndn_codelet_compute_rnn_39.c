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
extern  float *input;
extern float (*noise_input);

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, processing every 2nd element in two passes
    // First pass: even indices
    for (int i = 0; i < 42; i += 2)
        noise_input[rnn->model->input_dense_size + rnn->model->vad_gru_size + i] = input[i];
    // Second pass: odd indices
    for (int i = 1; i < 42; i += 2)
        noise_input[rnn->model->input_dense_size + rnn->model->vad_gru_size + i] = input[i];
}
