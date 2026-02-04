#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < w2; i++) {
        dest[i] = dest[w2 - i];
        i++; 
    }
}
