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

extern  DenseLayer *layer;
extern float *output;
extern  float *input;
extern  int N;
extern  int M;
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *out = output;
    const float *bias = layer->bias;
    const float *weights = layer->input_weights;
    const float *inp = input;
    int nb_inputs = M;
    int stride_local = stride;

    for (int i = 0; i < N; i++) {
        float sum = bias[i];
        for (int j = 0; j < nb_inputs; j++) {
            sum += weights[i + j * stride_local] * inp[j];
        }
        out[i] = (1.F / 256) * sum;
    }
}
