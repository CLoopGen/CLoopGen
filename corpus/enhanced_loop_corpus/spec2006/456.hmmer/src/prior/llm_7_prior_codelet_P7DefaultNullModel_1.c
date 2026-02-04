#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (x = 0; x < Alphabet_size; x++) {
        temp += 1.0f / (float)(Alphabet_size + x);
        null[x] = temp;
    }
}
