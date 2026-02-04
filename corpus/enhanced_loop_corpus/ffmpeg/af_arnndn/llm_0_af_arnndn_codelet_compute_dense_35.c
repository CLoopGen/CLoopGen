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
    float scale = 1.F / 256;
    for (int i = 0; i < N; i++) {
        float sum = layer->bias[i];
        int index = i;
        for (int j = 0; j < M; j++, index += stride)
            sum += layer->input_weights[index] * input[j];
        output[i] = scale * sum;
    }
}
