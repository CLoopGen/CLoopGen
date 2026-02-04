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
for (x = 1; x < w2 - 1; x++) {
    b[2 * x] = ((int)(tmp[x] + 3U)) >> 2;
    int filtered = (int)(9U * tmp[x] + 6U * tmp[x + 1] - 3U * tmp[x + 2] - 2U * tmp[x - 1] - tmp[x - 2] + 16) >> 5;
    int adjusted = ((int)((unsigned int)(b[x + w2]) + filtered) + 2U) >> 2;
    b[2 * x + 1] = adjusted;
}
}
