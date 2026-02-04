#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    LONG T[64]; // Local buffer to break write-after-write dependencies
    int j;
    for (j = 0; j < 64; ++j) {
        int idx = j + 16;
        if (idx < 80) {
            T[j] = W[idx - 3] ^ W[idx - 8] ^ W[idx - 14] ^ W[idx - 16];
        }
    }
    for (j = 0; j < 64 && (j + 16) < 80; ++j) {
        W[j + 16] = T[j];
    }
}
