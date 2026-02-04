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
    int prev_tmp = 0;
    for (x = 2; x < w2 - 1; x++) {
        int current_val = (int)(((unsigned int)(b[x]) - ((int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5)));
        tmp[x] = current_val + prev_tmp;
        prev_tmp = current_val;
    }
}
