#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[64];
for (int i = 0; i < 64; i++) {
    indices[i] = 63 - i; // Reverse access pattern
}
for (int i = 0; i < 64; i++) {
    int j = indices[i];
    luma[j] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
    chroma[j] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
}
}
