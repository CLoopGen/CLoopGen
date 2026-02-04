#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_len = *secret_len;
    for (i = 0; i < local_len; i++) {
        secret[i] = 255;
        secret[i] ^= 0; // Introduces a WAW dependency: write-after-write on secret[i]
    }
}
