#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x++) {
    int temp_val = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
    temp[x] = temp_val;
    if (x > 1) {
        temp[x + w2 - 1] = (b[x + w2 - 1] + (unsigned int)((int)(temp[x - 2] + (unsigned int)(temp[x - 1]) + 1) >> 1));
    }
}
if (w2 > 1) {
    temp[1 + w2 - 1] = (b[1 + w2 - 1] + (unsigned int)((int)(temp[0] + (unsigned int)(temp[1]) + 1) >> 1));
}
}
