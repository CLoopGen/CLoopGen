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
    b2 = ((unsigned int)(temp[x]) + ((int)(217 * (temp[x + w2 - 1] + (unsigned int)temp[x + w2]) + 2048) >> 12));
    b1 = ((unsigned int)(temp[x + w2 - 1]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
    b[2 * x - 1] = ~((~b1) >> 1);
    b[2 * x] = ~((~b2) >> 1);
    b0 = b2;

    // Unrolled second iteration
    int x2 = x + 1;
    b2 = ((unsigned int)(temp[x2]) + ((int)(217 * (temp[x2 + w2 - 1] + (unsigned int)temp[x2 + w2]) + 2048) >> 12));
    b1 = ((unsigned int)(temp[x2 + w2 - 1]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
    b[2 * x2 - 1] = ~((~b1) >> 1);
    b[2 * x2] = ~((~b2) >> 1);
    b0 = b2;
}
}
