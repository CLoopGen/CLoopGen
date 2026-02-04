#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TonalComponent {
    int pos;
    int num_coefs;
    float coef[8];
} TonalComponent;

extern float *spectrum;
extern int num_components;
extern TonalComponent *components;
extern int i;
extern int j;
extern int last_pos;
extern float *input;
extern float *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing components in natural order, traverse them with a stride of 2,
    // processing even indices first, then odd indices to create strided access to components array.
    int stride = 2;
    for (i = 0; i < num_components; i += stride) {
        last_pos = ((components[i].pos + components[i].num_coefs) > (last_pos) ? (components[i].pos + components[i].num_coefs) : (last_pos));
        input = components[i].coef;
        output = &spectrum[components[i].pos];
        for (j = 0; j < components[i].num_coefs; j++)
            output[j] += input[j];
    }
    for (i = 1; i < num_components; i += stride) {
        last_pos = ((components[i].pos + components[i].num_coefs) > (last_pos) ? (components[i].pos + components[i].num_coefs) : (last_pos));
        input = components[i].coef;
        output = &spectrum[components[i].pos];
        for (j = 0; j < components[i].num_coefs; j++)
            output[j] += input[j];
    }
}
