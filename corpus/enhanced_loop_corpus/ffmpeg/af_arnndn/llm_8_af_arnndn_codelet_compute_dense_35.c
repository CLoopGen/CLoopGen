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
    for (int i = 0; i < N; i += 2) {
        float sum1 = layer->bias[i];
        float sum2 = (i + 1 < N) ? layer->bias[i + 1] : 0.0f;
        for (int j = 0; j < M; j++) {
            sum1 += layer->input_weights[j * stride + i] * input[j];
            if (i + 1 < N)
                sum2 += layer->input_weights[j * stride + i + 1] * input[j];
        }
        output[i] = (1.F / 256) * sum1;
        if (i + 1 < N)
            output[i + 1] = (1.F / 256) * sum2;
    }
}
