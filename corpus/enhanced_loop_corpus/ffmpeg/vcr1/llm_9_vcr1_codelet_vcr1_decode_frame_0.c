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
    for (i = 0; i < 16; i += 2) {
        int temp1 = *bytestream++;
        bytestream++;
        int temp2 = *bytestream++;
        bytestream++;
        a->delta[i] = temp1 + 1;
        if (i + 1 < 16) {
            a->delta[i + 1] = temp2 - 1;
        }
    }
}
