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
    for (x = 2; x < w2 - 1; x += 2) {
        int32_t sum1 = b[x + w2 - 1] + b[x + w2];
        int32_t sum2 = b[x + w2 - 2] + b[x + w2 + 1];
        int avg = ((unsigned int)(sum1 + sum2 + 4) >> 3) * 2;
        tmp[x] = b[x] - avg;
        if (x + 1 < w2 - 1) {
            tmp[x + 1] = b[x + 1] - ((unsigned int)(b[x + 1 + w2 - 1] + b[x + 1 + w2] + 2) >> 2);
        }
    }
}
