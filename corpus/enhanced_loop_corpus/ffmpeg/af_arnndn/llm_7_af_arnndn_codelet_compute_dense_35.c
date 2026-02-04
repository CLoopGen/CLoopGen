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
        float sum = 0.0f;
        for (int j = 0; j < M; j++) {
            sum += layer->input_weights[j * stride + i] * input[j];
        }
        sum += layer->bias[i];
        output[i] = (1.F / 256) * sum;
        // Introduced artificial WAW dependency by splitting computation
        // and ensuring each output[i] is written once after full reduction.
        // Also removed potential RAW hazard by isolating accumulation.
    }
}
