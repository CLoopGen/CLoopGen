#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Alphabet_size; x += 2) {
        if (x + 1 < Alphabet_size) {
            null[x] = 0.25;
            null[x + 1] = 0.25;
        } else {
            null[x] = 0.25;
        }
    }
}
