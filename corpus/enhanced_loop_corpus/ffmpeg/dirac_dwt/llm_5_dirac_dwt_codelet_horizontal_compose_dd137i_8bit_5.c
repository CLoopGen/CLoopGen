#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 2; x < w2 - 1; x++) {
        int computed_val = (int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5;
        unsigned int diff = (unsigned int)(b[x]) - computed_val;
        if (diff > 0) {
            tmp[x] = (int)diff;
        }
    }
}
