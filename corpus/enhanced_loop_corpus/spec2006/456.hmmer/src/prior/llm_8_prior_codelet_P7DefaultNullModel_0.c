#include <stdio.h>

#include <inttypes.h>

extern float aafq[];
extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Alphabet_size; x += 2) {
        if (x + 1 < Alphabet_size) {
            null[x]     = aafq[x];
            null[x + 1] = aafq[x + 1];
        } else {
            null[x] = aafq[x];
        }
    }
}
