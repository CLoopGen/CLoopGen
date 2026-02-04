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
    for (x = 2; x < w2 - 1; x++) {
        int offset = x + w2;
        tmp[x] = (int)(((unsigned int)(b[x]) - ((int)(9U * b[offset] + 9U * b[offset + 0] - b[offset + 1] - b[offset - 2] + 16) >> 5)));
    }
}
