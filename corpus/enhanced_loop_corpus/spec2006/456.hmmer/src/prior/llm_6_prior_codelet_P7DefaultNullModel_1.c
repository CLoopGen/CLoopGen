#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_alphabet = 1.0f / (float)Alphabet_size;
    for (x = 0; x < Alphabet_size; x++)
        null[x] = inv_alphabet;
}
