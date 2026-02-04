#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float val = 0.25f;
    for (x = 0; x < Alphabet_size * 2; x++) {
        int idx = x / 2;
        if (x % 2 == 0) {
            null[idx] = val * 1.0f;
        } else {
            null[idx] = val * 1.0f;
        }
    }
}
