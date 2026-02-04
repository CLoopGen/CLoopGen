#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *vec;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (q = 0; q < Alphabet_size; q++)
    mix[q] = vec[q];

}
