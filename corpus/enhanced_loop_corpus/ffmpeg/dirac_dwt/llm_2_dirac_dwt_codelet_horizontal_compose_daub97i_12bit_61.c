#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x++) {
    int idx_temp1 = x;
    int idx_temp2 = x + w2 - 1;
    int idx_temp3 = x + w2;
    b2 = ((unsigned int)(temp[idx_temp1]) + ((int)(217 * (temp[idx_temp2] + (unsigned int)temp[idx_temp3]) + 2048) >> 12));
    b1 = ((unsigned int)(temp[idx_temp2]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
    int base_b_idx = 2 * x;
    b[base_b_idx - 1] = ~((~b1) >> 1);
    b[base_b_idx] = ~((~b2) >> 1);
    b0 = b2;
}
}
