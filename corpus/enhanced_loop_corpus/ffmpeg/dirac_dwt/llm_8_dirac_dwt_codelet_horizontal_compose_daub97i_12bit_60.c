#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < w2 - 1; x += 2) {
    temp[x] = ((unsigned int)(b[x]) - ((int)(1817 * (b[x + w2 - 1] + (unsigned int)b[x + w2]) + 2048) >> 12));
    temp[x + w2 - 1] = ((unsigned int)(b[x + w2 - 1]) - ((int)(113 * (temp[x - 1] + (unsigned int)temp[x]) + 64) >> 7));
    temp[x + 1] = ((unsigned int)(b[x + 1]) - ((int)(1817 * (b[x + 1 + w2 - 1] + (unsigned int)b[x + 1 + w2]) + 2048) >> 12));
    temp[x + 1 + w2 - 1] = ((unsigned int)(b[x + 1 + w2 - 1]) - ((int)(113 * (temp[x] + (unsigned int)temp[x + 1]) + 64) >> 7));
}
}
