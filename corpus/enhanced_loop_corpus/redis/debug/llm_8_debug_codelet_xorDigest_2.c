#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *digest;
extern unsigned char hash[20];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 20; j += 2) {
        digest[j] ^= hash[j];
        if (j + 1 < 20) {
            digest[j + 1] ^= hash[j + 1];
        }
    }
}
