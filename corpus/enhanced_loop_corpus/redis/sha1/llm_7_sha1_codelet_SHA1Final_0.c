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
    uint32_t c0 = context->count[1];
    uint32_t c1 = context->count[0];
    for (i = 0; i < 4; i++) {
        int shift = (3 - i) * 8;
        finalcount[i]       = (unsigned char)((c0 >> shift) & 255);
        finalcount[i + 4]   = (unsigned char)((c1 >> shift) & 255);
    }
}
