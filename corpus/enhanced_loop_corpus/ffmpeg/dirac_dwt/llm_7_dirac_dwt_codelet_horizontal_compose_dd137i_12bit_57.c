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
    int prev_x = 2;
    if (w2 > 3) {
        tmp[2] = (int)(((unsigned int)(b[2]) - ((int)(9U * b[2 + w2 - 1] + 9U * b[2 + w2] - b[2 + w2 + 1] - b[2 + w2 - 2] + 16) >> 5)));
        for (x = 3; x < w2 - 1; x++) {
            tmp[x] = (int)(((unsigned int)(b[x]) - ((int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5))) + tmp[prev_x];
            prev_x = x;
        }
    }
}
