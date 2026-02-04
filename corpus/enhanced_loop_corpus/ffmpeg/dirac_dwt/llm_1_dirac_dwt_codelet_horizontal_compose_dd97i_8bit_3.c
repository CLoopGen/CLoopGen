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
    for (int outer = 1; outer < w2; outer += 2) {
        if (outer < w2) {
            tmp[outer] = (b[outer] - (unsigned int)((int)(b[outer + w2 - 1] + (unsigned int)(b[outer + w2]) + 2) >> 2));
        }
        if (outer + 1 < w2) {
            tmp[outer + 1] = (b[outer + 1] - (unsigned int)((int)(b[outer + 1 + w2 - 1] + (unsigned int)(b[outer + 1 + w2]) + 2) >> 2));
        }
    }
}
