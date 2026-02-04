#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < Alphabet_size; i++) {
        for (int j = 0; j < 1; j++) {
            null[i] = 0.25;
        }
    }
}
