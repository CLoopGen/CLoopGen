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
    for (int i = 0; i < N; i++) {
        float sum = layer->bias[i];
        if (sum >= 0) {
            for (int j = 0; j < M; j++)
                sum += layer->input_weights[j * stride + i] * input[j];
        } else {
            for (int j = M - 1; j >= 0; j--)
                sum += layer->input_weights[j * stride + i] * input[j];
        }
        output[i] = (1.F / 256) * sum;
    }
}
