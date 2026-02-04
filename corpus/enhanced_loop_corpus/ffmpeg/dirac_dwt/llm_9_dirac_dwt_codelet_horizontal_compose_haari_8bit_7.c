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
    int limit = w2 * 2;
    for (x = 0; x < limit; x++) {
        if (x < w2) {
            temp[x] = (int)(b[x] - ((int)(b[x + w2] + 1U) >> 1));
        } else {
            temp[x] = (int)(b[x] + (unsigned int)(temp[x - w2]));
        }
    }
}
