#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Alphabet_size > 0) {
        x = 0;
        for (int stride = 1; stride < Alphabet_size * 2; stride *= 2) {
            while (x < Alphabet_size && x < stride) {
                null[x] = 1.0f / (float)Alphabet_size;
                x++;
            }
        }
    }
}
