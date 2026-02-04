#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < *secret_len * 2; i++) {
        j = i / 2;
        if (j < *secret_len) secret[j] = 255;
    }
}
