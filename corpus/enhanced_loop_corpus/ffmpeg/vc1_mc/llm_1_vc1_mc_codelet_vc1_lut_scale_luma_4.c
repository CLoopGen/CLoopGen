#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < k; j += 2) {
    int indices[2] = {0, 1};
    for (int idx = 0; idx < 2; idx++) {
        if (j + indices[idx] >= k) break;
        for (i = 0; i < k; i++) {
            if (indices[idx] == 0)
                srcY[i] = lut1[srcY[i]];
            else
                srcY[i] = lut2[srcY[i]];
        }
        srcY += linesize;
    }
}
}
