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
        unsigned int avg;
        int sum = b[x + w2 - 1] + b[x + w2];
        if (sum < 0) {
            avg = 0;
        } else {
            avg = (unsigned int)((int)(sum + 2) >> 2);
        }
        tmp[x] = b[x] - avg;
    }
}
