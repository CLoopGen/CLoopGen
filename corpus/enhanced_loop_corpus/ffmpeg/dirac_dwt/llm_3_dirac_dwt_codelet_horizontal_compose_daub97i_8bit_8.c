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
    int idx_b_current = x;
    int idx_b_next_row1 = x + w2 - 1;
    int idx_b_next_row2 = x + w2;
    int idx_temp_prev = x - 1;
    temp[idx_b_current] = ((unsigned int)(b[idx_b_current]) - ((int)(1817 * ((unsigned int)b[idx_b_next_row1] + (unsigned int)b[idx_b_next_row2]) + 2048) >> 12));
    temp[idx_b_next_row1] = ((unsigned int)(b[idx_b_next_row1]) - ((int)(113 * ((unsigned int)temp[idx_temp_prev] + (unsigned int)temp[idx_b_current]) + 64) >> 7));
}
}
