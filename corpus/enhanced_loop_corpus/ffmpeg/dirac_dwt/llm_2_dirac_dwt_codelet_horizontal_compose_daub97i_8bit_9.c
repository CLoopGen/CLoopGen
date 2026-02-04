#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2; x++) {
        int idx_temp_1 = x;
        int idx_temp_2 = x + w2 - 1;
        int idx_temp_3 = x + w2;

        b2 = ((unsigned int)(temp[idx_temp_1]) + ((int)(217 * (temp[idx_temp_2] + (unsigned int)temp[idx_temp_3]) + 2048) >> 12));
        b1 = ((unsigned int)(temp[idx_temp_2]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));

        int idx_b_1 = 2 * x - 1;
        int idx_b_2 = 2 * x;

        b[idx_b_1] = ~((~b1) >> 1);
        b[idx_b_2] = ~((~b2) >> 1);

        b0 = b2;
    }
}
