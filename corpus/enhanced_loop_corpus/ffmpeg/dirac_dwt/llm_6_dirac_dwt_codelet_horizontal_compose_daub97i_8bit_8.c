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
    int16_t b_val = b[x];
    int16_t neighbor_sum = (unsigned int)b[x + w2 - 1] + (unsigned int)b[x + w2];
    temp[x] = ((unsigned int)(b_val) - ((int)(1817 * neighbor_sum + 2048) >> 12));
}
for (x = 1; x < w2; x++) {
    int16_t temp_prev = temp[x - 1];
    int16_t temp_curr = temp[x];
    temp[x + w2 - 1] = ((unsigned int)(b[x + w2 - 1]) - ((int)(113 * ((unsigned int)temp_prev + (unsigned int)temp_curr) + 64) >> 7));
}
}
