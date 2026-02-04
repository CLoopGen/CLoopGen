#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in two passes: first even indices, then odd indices
    int i, j;
    for (i = 0; i < len; i += 2) {
        k[i] = data[i];
    }
    for (j = 1; j < len; j += 2) {
        k[j] = data[j];
    }
}
