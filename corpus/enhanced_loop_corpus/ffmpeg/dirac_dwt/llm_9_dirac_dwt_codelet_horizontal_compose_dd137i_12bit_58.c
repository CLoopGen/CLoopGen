#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x++) {
        int32_t t = tmp[x];
        b[2 * x] = (t + 1) >> 1;
        if (x > 0 && x < w2 - 1) {
            int32_t neighborhood = 9U * t + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8;
            int32_t shifted = (neighborhood >> 4);
            int32_t combined = ((unsigned int)b[x + w2] + shifted + 1U) >> 1;
            b[2 * x + 1] = combined;
        } else {
            b[2 * x + 1] = (tmp[x] + 1U) >> 1;
        }
    }
}
