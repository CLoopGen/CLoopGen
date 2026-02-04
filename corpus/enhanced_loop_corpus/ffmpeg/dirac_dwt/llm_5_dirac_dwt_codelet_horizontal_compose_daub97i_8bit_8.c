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
        const int index1 = x + w2 - 1;
        const int index2 = x + w2;
        unsigned int term1 = (unsigned int)b[index1] + (unsigned int)b[index2];
        temp[x] = (unsigned int)(b[x]) - ((int)(1817 * term1 + 2048) >> 12);

        if (index1 < w2 * 2 - 1) {
            unsigned int term2 = (unsigned int)temp[x - 1] + (unsigned int)temp[x];
            temp[index1] = (unsigned int)(b[index1]) - ((int)(113 * term2 + 64) >> 7);
        }
    }
}
