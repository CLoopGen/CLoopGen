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
for (int i = 0; i < w2; i += 2) {
    for (int j = 0; j < 2 && (i + j) < w2; j++) {
        x = i + j;
        b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
    }
}
}
