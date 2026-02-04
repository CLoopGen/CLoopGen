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
        for (int j = 0; j < M; j += 4) {
            float prod = 0.0f;
            for (int k = 0; k < 4 && (j + k) < M; k++)
                prod += layer->input_weights[(j + k) * stride + i] * input[j + k];
            sum += prod;
        }
        output[i] = (1.F / 256) * sum;
    }
}
