#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 1; i < w2; i++) {
    for (int j = 0; j < 1; j++) {
        tmp[i] = (b[i] - (unsigned int)((int)(b[i + w2 - 1] + (unsigned int)(b[i + w2]) + 2) >> 2));
    }
}
}
