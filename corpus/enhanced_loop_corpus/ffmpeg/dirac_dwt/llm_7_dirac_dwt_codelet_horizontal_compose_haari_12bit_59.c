#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *b;
extern int32_t *temp;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x++) {
        int t = (int)(b[x] - (unsigned int)((int)(b[x + w2] + 1U) >> 1));
        temp[x] = t;
        temp[x + w2] = ((int)(b[x + w2] + (unsigned int)(t)));
    }
}
