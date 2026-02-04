#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < k; j++) {
        if (k > 0) {
            for (i = 0; i < k; i++) {
                int diff = srcY[i] - 128;
                if (diff >= 0) {
                    srcY[i] = (diff >> 1) + 128;
                }
            }
        }
        srcY += linesize;
    }
}
