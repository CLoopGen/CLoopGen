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
extern float (*noise_input);

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = rnn->model->vad_gru_size;
    int input_size = rnn->model->input_dense_size;
    float *state = rnn->vad_gru_state;
    float *input = noise_input + input_size;
    
    for (int i = 0; i < size; i += 4) {
        input[i]     = state[i];
        if (i + 1 < size) input[i + 1] = state[i + 1];
        if (i + 2 < size) input[i + 2] = state[i + 2];
        if (i + 3 < size) input[i + 3] = state[i + 3];
    }
}
