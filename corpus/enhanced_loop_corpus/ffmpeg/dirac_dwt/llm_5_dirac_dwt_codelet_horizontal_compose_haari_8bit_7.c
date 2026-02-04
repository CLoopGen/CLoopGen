#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *b;
extern int16_t *temp;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x++) {
        int diff = (int)(b[x + w2] + 1U) >> 1;
        temp[x] = b[x] - diff;
        if (temp[x] >= 0) {
            temp[x + w2] = b[x + w2] + (unsigned int)(temp[x]);
        } else {
            temp[x + w2] = b[x + w2];
        }
    }
}
