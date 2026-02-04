#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 1; outer < w2; outer += 2) {
        for (x = outer; x < outer + 2 && x < w2; x++) {
            temp[x] = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
            temp[x + w2 - 1] = (b[x + w2 - 1] + (unsigned int)((int)(temp[x - 1] + (unsigned int)(temp[x]) + 1) >> 1));
        }
    }
}
