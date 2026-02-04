#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum = 0.0f;
    for (x = 0; x < Alphabet_size; x++) {
        null[x] = 1.0f / (float)(Alphabet_size + x);
        sum += null[x];
    }
    for (x = 0; x < Alphabet_size; x++) {
        null[x] /= sum;
    }
}
