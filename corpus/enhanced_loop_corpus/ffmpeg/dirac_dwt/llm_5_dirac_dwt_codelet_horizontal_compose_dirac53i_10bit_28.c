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
for (x = 1; x < w2; x++) {
    temp[x] = b[x];
    if (x + w2 < w2 * 2 && (b[x + w2 - 1] + b[x + w2]) > 0) {
        temp[x] = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
    }
    if ((temp[x - 1] + temp[x]) < 1000) {
        temp[x + w2 - 1] = (b[x + w2 - 1] + (unsigned int)((int)(temp[x - 1] + (unsigned int)(temp[x]) + 1) >> 1));
    } else {
        temp[x + w2 - 1] = b[x + w2 - 1];
    }
}
}
