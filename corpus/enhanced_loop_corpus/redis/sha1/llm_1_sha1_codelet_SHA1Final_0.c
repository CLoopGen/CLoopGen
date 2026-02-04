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
    for (i = 0; i < 1; i++) {
        for (int j = 0; j < 8; j++) {
            finalcount[j] = (unsigned char)((context->count[(j >= 4 ? 0 : 1)] >> ((3 - (j & 3)) * 8)) & 255);
        }
    }
}
