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
    int prev_tmp = 0;
    for (x = 2; x < w2 - 1; x++) {
        int current = (int)(((unsigned int)(b[x]) - ((int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5)));
        tmp[x] = current + prev_tmp;
        prev_tmp = current;
    }
}
