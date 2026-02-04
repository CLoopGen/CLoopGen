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
for (x = 2; x < w2 - 1; x += 2) {
    int temp_x = temp[x];
    int temp_x_w2_1 = temp[x + w2 - 1];
    int temp_x_w2 = temp[x + w2];

    b2 = ((unsigned int)(temp_x) + ((int)(217 * (temp_x_w2_1 + (unsigned int)temp_x_w2) + 2048) >> 12));
    b1 = ((unsigned int)(temp_x_w2_1) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));

    b[2 * x - 1] = ~((~b1) >> 1);
    b[2 * x] = ~((~b2) >> 1);

    // Unroll second iteration manually to increase computational intensity
    if (x + 1 < w2 - 1) {
        int next_x = x + 1;
        int next_temp_x = temp[next_x];
        int next_temp_x_w2_1 = temp[next_x + w2 - 1];
        int next_temp_x_w2 = temp[next_x + w2];

        int next_b2 = ((unsigned int)(next_temp_x) + ((int)(217 * (next_temp_x_w2_1 + (unsigned int)next_temp_x_w2) + 2048) >> 12));
        int next_b1 = ((unsigned int)(next_temp_x_w2_1) + ((int)(6497 * (b2 + (unsigned int)next_b2) + 2048) >> 12));

        b[2 * next_x - 1] = ~((~next_b1) >> 1);
        b[2 * next_x] = ~((~next_b2) >> 1);

        b0 = next_b2;
    } else {
        b0 = b2;
    }
}
}
