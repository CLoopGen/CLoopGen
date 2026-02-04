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
for (x = 0; x < w2 - 1; x++) {
    int idx = x * 2 + 1;
    if (idx < w2 && idx + w2 - 1 < w2 * 2) {
        temp[idx] = (b[idx] - (unsigned int)((int)(b[idx + w2 - 1] + (unsigned int)(b[idx + w2]) + 2) >> 2));
        temp[idx + w2 - 1] = (b[idx + w2 - 1] + (unsigned int)((int)(temp[idx - 1] + (unsigned int)(temp[idx]) + 1) >> 1));
    }
}
}
