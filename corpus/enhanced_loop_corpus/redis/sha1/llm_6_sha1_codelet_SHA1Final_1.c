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
    uint32_t temp_state[5];
    for (i = 0; i < 5; i++) {
        temp_state[i] = context->state[i];
    }
    for (i = 0; i < 20; i++) {
        uint32_t shifted = temp_state[i >> 2] >> ((3 - (i & 3)) * 8);
        digest[i] = (unsigned char)(shifted & 255);
    }
}
