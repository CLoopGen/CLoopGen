#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VCR1Context {
    int delta[16];
    int offset[4];
} VCR1Context;

extern VCR1Context * a;
extern  uint8_t *bytestream;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        if (i % 2 == 0) {
            a->delta[i] = *bytestream++;
        } else {
            bytestream++;
            a->delta[i] = *bytestream++;
            bytestream++;
        }
    }
}
