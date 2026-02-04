#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *b;
extern int32_t *temp;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2 * 2; x++) {
        if (x < w2) {
            temp[x] = (int)(b[x] - (unsigned int)((int)(b[x + w2] + 3U) >> 2));
        } else {
            int idx = x - w2;
            temp[x] = (int)(b[x] + (unsigned int)((temp[idx] + 1) >> 1));
        }
    }
}
