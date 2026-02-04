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
    for (x = 0; x < w2; x += 2) {
        if (x + 1 < w2) {
            temp[x] = b[x] - ((b[x + w2] + 1U) >> 1);
            temp[x + 1] = b[x + 1] - ((b[x + 1 + w2] + 1U) >> 1);
            temp[x + w2] = b[x + w2] + temp[x];
            temp[x + 1 + w2] = b[x + 1 + w2] + temp[x + 1];
        } else {
            temp[x] = b[x] - ((b[x + w2] + 1U) >> 1);
            temp[x + w2] = b[x + w2] + temp[x];
        }
    }
}
