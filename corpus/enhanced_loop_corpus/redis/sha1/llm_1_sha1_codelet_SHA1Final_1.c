#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

extern unsigned char digest[20];
extern SHA1_CTX *context;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1; i++) {
        for (unsigned int j = 0; j < 20; j++) {
            digest[j] = (unsigned char)((context->state[j >> 2] >> ((3 - (j & 3)) * 8)) & 255);
        }
    }
}
