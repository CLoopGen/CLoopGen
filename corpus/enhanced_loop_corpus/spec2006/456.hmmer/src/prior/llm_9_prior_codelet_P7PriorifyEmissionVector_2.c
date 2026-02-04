#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *vec;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (q = 0; q < Alphabet_size; q++) {
        float sum = 0.0f;
        for (i = 0; i < 3; i++) {
            sum += vec[q] * 0.333f;
        }
        mix[q] = sum;
    }
}
