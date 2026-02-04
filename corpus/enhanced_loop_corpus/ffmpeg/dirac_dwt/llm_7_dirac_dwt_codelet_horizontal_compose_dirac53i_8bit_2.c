#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (x = 1; x < w2; x++) {
        int16_t t_val = (b[x] - ((unsigned int)((int)(b[x + w2] + b[x + w2 + 1] + 2) >> 2)));
        temp[x] = t_val;
        temp[x + w2 - 1] = (b[x + w2 - 1] + ((unsigned int)((int)(t_val + temp[x - 1] + 1) >> 1)));
    }
}
