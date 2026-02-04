#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = w2;
    for (x = 1; x < w2; x += 2) {
        int val1 = (x + offset - 1 < w2 + x) ? (unsigned int)(b[x + offset - 1] + b[x + offset] + 2) >> 2 : 0;
        tmp[x] = b[x] - val1;
        if (x + 1 < w2) {
            int val2 = (unsigned int)(b[x + 1 + offset - 1] + b[x + 1 + offset] + 2) >> 2;
            tmp[x + 1] = b[x + 1] - val2;
        }
    }
}
