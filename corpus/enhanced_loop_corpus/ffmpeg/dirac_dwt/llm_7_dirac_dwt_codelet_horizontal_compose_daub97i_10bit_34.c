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
int32_t prev_temp = 0;
for (x = 1; x < w2; x++) {
    temp[x] = ((unsigned int)(b[x]) - ((int)(1817 * (b[x + w2 - 1] + (unsigned int)b[x + w2]) + 2048) >> 12));
    if (x > 1) {
        temp[x + w2 - 1] = ((unsigned int)(b[x + w2 - 1]) - ((int)(113 * (prev_temp + (unsigned int)temp[x]) + 64) >> 7));
    }
    prev_temp = temp[x];
}
// Handle last iteration's second assignment outside the main dependency chain
if (w2 > 1) {
    temp[1 + w2 - 1] = ((unsigned int)(b[1 + w2 - 1]) - ((int)(113 * (temp[0] + (unsigned int)temp[1]) + 64) >> 7));
}
}
