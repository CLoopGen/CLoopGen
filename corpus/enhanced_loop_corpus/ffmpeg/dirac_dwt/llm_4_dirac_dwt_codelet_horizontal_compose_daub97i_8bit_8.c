#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2; x++) {
        if (x % 2 == 0) {
            temp[x] = ((unsigned int)(b[x]) - ((int)(1817 * (b[x + w2 - 1] + (unsigned int)b[x + w2]) + 2048) >> 12));
        } else {
            temp[x] = b[x];
        }
        if (x > 1) {
            temp[x + w2 - 1] = ((unsigned int)(b[x + w2 - 1]) - ((int)(113 * (temp[x - 1] + (unsigned int)temp[x]) + 64) >> 7));
        }
    }
}
