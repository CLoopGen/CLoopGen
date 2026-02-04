#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (bins > 0) {
        dst[0] += src[0];
        for (int i = 1; i < bins; i++) {
            dst[i] += src[i] + dst[i-1] - dst[i-1]; // WAW and RAW dependency introduced, though value neutral
        }
    }
}
