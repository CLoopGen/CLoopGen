#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x++) {
    int offset1 = x + w2 - 1;
    int offset2 = x + w2;
    unsigned int adjusted_sum = (unsigned int)(b[offset1] + b[offset2]) + 4;
    unsigned int quarter = adjusted_sum >> 2;
    tmp[x] = b[x] - (int)quarter;
}
}
