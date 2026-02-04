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

static float *input_weights_data;
static float *bias_data;
static float *input_data;
static float *output_data;
DenseLayer *layer;
float *output;
float *input;
int N;
int M;
int stride;

void init_vars() {
    N = 1024;
    M = 1024;
    stride = N;

    size_t input_weights_size = M * stride * sizeof(float);
    size_t bias_size = N * sizeof(float);
    size_t input_size = M * sizeof(float);
    size_t output_size = N * sizeof(float);

    input_weights_data = (float*)aligned_alloc(32, input_weights_size);
    bias_data = (float*)aligned_alloc(32, bias_size);
    input_data = (float*)aligned_alloc(32, input_size);
    output_data = (float*)aligned_alloc(32, output_size);

    for (int i = 0; i < M * stride; i++) {
        input_weights_data[i] = (float)(i % 256) / 255.0f;
    }
    for (int i = 0; i < N; i++) {
        bias_data[i] = 1.0f;
    }
    for (int i = 0; i < M; i++) {
        input_data[i] = (float)((i * 7) % 256) / 255.0f;
    }
    for (int i = 0; i < N; i++) {
        output_data[i] = 0.0f;
    }

    layer = (DenseLayer*)malloc(sizeof(DenseLayer));
    layer->bias = bias_data;
    layer->input_weights = input_weights_data;
    layer->nb_inputs = M;
    layer->nb_neurons = N;
    layer->activation = 0;

    input = input_data;
    output = output_data;
}