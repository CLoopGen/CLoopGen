#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < Alphabet_size; x += 2) {
        null[x - 1] = 0.25;
        if (x < Alphabet_size) {
            null[x] = 0.25;
        }
    }
    if (Alphabet_size > 0 && Alphabet_size % 2 == 1) {
        null[Alphabet_size - 1] = 0.25;
    }
}
