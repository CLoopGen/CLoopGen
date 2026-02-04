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
for (x = 1; x < w2; x++) {
    int32_t val1 = b[x + w2 - 1];
    int32_t val2 = b[x + w2];
    int32_t sum = val1 + val2;
    int32_t scaled = (1817 * sum + 2048) >> 12;
    temp[x] = ((unsigned int)(b[x]) - (unsigned int)scaled);
    
    int32_t prev_temp_sum = temp[x - 1] + temp[x];
    int32_t feedback = (113 * prev_temp_sum + 64) >> 7;
    temp[x + w2 - 1] = ((unsigned int)(b[x + w2 - 1]) - (unsigned int)feedback);
}
}
