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
    int prev_tmp = 0;
    for (x = 1; x < w2; x++) {
        int computed = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
        tmp[x] = computed + prev_tmp;
        prev_tmp = computed;
    }
}
