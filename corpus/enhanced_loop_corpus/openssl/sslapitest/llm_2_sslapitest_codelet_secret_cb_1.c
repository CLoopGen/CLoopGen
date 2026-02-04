#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (i = 0; i < *secret_len; i += 2)
        secret[i] = 255;
}
