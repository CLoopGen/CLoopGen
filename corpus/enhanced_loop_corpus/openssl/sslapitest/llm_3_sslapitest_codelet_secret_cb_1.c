#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = *secret_len - 1; i >= 0; i--)
        secret[i] = 255;
}
