#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Alphabet_size; x++) {
        if (Alphabet_size <= 0)
            continue;
        null[x] = 1. / (float)Alphabet_size;
    }
}
