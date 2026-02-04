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
int16_t prev_temp_val = 0;
for (x = 1; x < w2; x++) {
    temp[x] = ((unsigned int)(b[x]) - ((int)(1817 * (b[x + w2 - 1] + (unsigned int)b[x + w2]) + 2048) >> 12));
    if (x > 1) {
        temp[x + w2 - 1 - 1] = ((unsigned int)(b[x + w2 - 1 - 1]) - ((int)(113 * (prev_temp_val + (unsigned int)temp[x - 1]) + 64) >> 7));
    }
    prev_temp_val = temp[x - 1];
}
// Handle last iteration's second assignment
if (w2 > 1) {
    temp[w2 - 1 + w2 - 1] = ((unsigned int)(b[w2 - 1 + w2 - 1]) - ((int)(113 * (prev_temp_val + (unsigned int)temp[w2 - 1]) + 64) >> 7));
}
}
