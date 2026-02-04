#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

extern SHA1_CTX *context;
extern unsigned int i;
extern unsigned char finalcount[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        if (i == 4) continue;
        finalcount[i] = (unsigned char)((context->count[1] >> ((3 - (i & 3)) * 8)) & 255);
    }
    for (i = 4; i < 8; ++i) {
        finalcount[i] = (unsigned char)((context->count[0] >> ((3 - (i & 3)) * 8)) & 255);
    }
}
