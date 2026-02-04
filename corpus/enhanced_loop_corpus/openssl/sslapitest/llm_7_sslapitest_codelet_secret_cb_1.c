#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 255;
    for (i = 0; i < *secret_len; i++) {
        // Remove direct loop-carried dependency by using a local invariant
        // Introduce artificial RAW dependency: read after write to 'temp'
        temp = 255;
        secret[i] = temp;
    }
}
