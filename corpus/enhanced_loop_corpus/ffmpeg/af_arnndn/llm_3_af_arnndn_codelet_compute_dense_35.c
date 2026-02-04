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

    for (int i = 0; i < N; i++) {
        float sum = bias[i];
        const float *w_ptr = &weights[i]; // Base pointer for neuron i, with fixed offset
        for (int j = 0; j < M; j += 4) {
            // Unrolled access with strided weight fetching: improves spatial locality in input
            sum += w_ptr[j * stride] * inp[j];
            if (j + 1 < M) sum += w_ptr[(j + 1) * stride] * inp[j + 1];
            if (j + 2 < M) sum += w_ptr[(j + 2) * stride] * inp[j + 2];
            if (j + 3 < M) sum += w_ptr[(j + 3) * stride] * inp[j + 3];
        }
        out[i] = (1.F / 256) * sum;
    }
}
