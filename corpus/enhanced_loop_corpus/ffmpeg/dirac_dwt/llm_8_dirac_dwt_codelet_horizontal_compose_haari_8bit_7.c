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
            temp[x] = (int)(b[x] - (unsigned int)((int)(b[x + w2] + 1U) >> 1));
            temp[x + 1] = (int)(b[x + 1] - (unsigned int)((int)(b[x + 1 + w2] + 1U) >> 1));
            temp[x + w2] = (int)(b[x + w2] + (unsigned int)(temp[x]));
            temp[x + 1 + w2] = (int)(b[x + 1 + w2] + (unsigned int)(temp[x + 1]));
        } else {
            temp[x] = (int)(b[x] - (unsigned int)((int)(b[x + w2] + 1U) >> 1));
            temp[x + w2] = (int)(b[x + w2] + (unsigned int)(temp[x]));
        }
    }
}
