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
    int limit = w2 * 3;
    for (x = 0; x < limit; x++) {
        int idx = x % w2;
        int shift = (x / w2) * w2;
        temp[idx + shift] = (int)(b[idx + shift] - (unsigned int)((int)(b[idx + shift + w2] + 1U) >> 1));
        temp[idx + shift + w2] = (int)(b[idx + shift + w2] + (unsigned int)(temp[idx + shift]));
    }
}
