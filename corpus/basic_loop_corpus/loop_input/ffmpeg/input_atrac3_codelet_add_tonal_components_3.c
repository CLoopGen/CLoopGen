#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TonalComponent {
    int pos;
    int num_coefs;
    float coef[8];
} TonalComponent;

float *spectrum;
int num_components;
TonalComponent *components;
int i;
int j;
int last_pos;
float *input;
float *output;

void init_vars() {
    const size_t spectrum_size = 64 * 1024 * 1024; // ~64MB to target 0.01 sec runtime
    spectrum = (float*)calloc(spectrum_size, sizeof(float));
    
    num_components = 200000; // Adjusted to ensure reasonable memory access without overflow
    components = (TonalComponent*)malloc(num_components * sizeof(TonalComponent));
    
    int current_pos = 0;
    for (int idx = 0; idx < num_components; idx++) {
        int num_coefs = (idx % 6) + 2; // Between 2 and 7, less than array size of 8
        components[idx].num_coefs = num_coefs;
        components[idx].pos = current_pos;
        
        for (int k = 0; k < num_coefs; k++) {
            components[idx].coef[k] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
        }
        
        current_pos += num_coefs;
        if (current_pos + 8 >= (int)spectrum_size) {
            num_components = idx + 1;
            break;
        }
    }

    last_pos = 0;
    input = NULL;
    output = NULL;
}