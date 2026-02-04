#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2 - 1; x += 2) {
        int32_t val = tmp[x];
        b[2 * x] = (val + 1U) >> 1;
        int32_t sum = 9U * val + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8;
        int32_t filtered = ((unsigned int)(b[x + w2]) + (sum >> 4)) + 1U;
        b[2 * x + 1] = filtered >> 1;
        b[2 * x + 2] = (tmp[x + 1] + 1U) >> 1;
        int32_t next_sum = 9U * tmp[x + 1] + 9U * tmp[x + 2] - tmp[x + 3] - tmp[x] + 8;
        int32_t next_filtered = ((unsigned int)(b[x + 1 + w2]) + (next_sum >> 4)) + 1U;
        b[2 * x + 3] = next_filtered >> 1;
    }
}
