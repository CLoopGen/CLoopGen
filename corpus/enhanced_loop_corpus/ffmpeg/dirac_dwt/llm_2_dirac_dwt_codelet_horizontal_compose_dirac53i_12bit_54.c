#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x += 2) {
    if (x + w2 - 1 < w2 * 2 - 1) {
        temp[x] = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
        temp[x + w2 - 1] = (b[x + w2 - 1] + (unsigned int)((int)(temp[x - 1] + (unsigned int)(temp[x]) + 1) >> 1));
    }
    if (x + 1 < w2 && x + w2 < w2 * 2 - 1) {
        temp[x + 1] = (b[x + 1] - (unsigned int)((int)(b[x + w2] + (unsigned int)(b[x + w2 + 1]) + 2) >> 2));
        temp[x + w2] = (b[x + w2] + (unsigned int)((int)(temp[x] + (unsigned int)(temp[x + 1]) + 1) >> 1));
    }
}
}
