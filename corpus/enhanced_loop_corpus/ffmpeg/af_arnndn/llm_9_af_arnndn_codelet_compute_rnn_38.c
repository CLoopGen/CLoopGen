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
    int total_ops = rnn->model->vad_gru_size * 2;
    float scale_factor = 1.0f;
    float offset = 0.5f;
    
    for (int i = 0; i < total_ops; i++) {
        int idx = i / 2;
        if (i % 2 == 0) {
            noise_input[idx + rnn->model->input_dense_size] = rnn->vad_gru_state[idx] * scale_factor + offset;
        } else {
            noise_input[idx + rnn->model->input_dense_size] = (noise_input[idx + rnn->model->input_dense_size] + rnn->vad_gru_state[idx]) * 0.5f;
        }
    }
}
