#include <stdio.h>

#include <inttypes.h>

extern float aafq[];
extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Alphabet_size > 0) {
        for (x = 0; x < Alphabet_size; x += 2) {
            null[x] = aafq[x];
            if (x + 1 < Alphabet_size)
                null[x + 1] = aafq[x + 1];
        }
    }
}
