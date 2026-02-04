#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < width * 2; i += 2) {
    for (j = 0; j < 4; j++) {
        if (i + j < width) {
            b1[i + j] -= (unsigned int)((int)(b0[i + j] + (unsigned int)b2[i + j] + 3) >> 2);
        }
    }
}
}
