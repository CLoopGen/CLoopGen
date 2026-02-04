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
for (x = 0; x < w2; x++) {
    int current_tmp = tmp[x];
    b[2 * x] = ((int)(current_tmp + 1U)) >> 1;
    int combined_input = (9U * current_tmp + 9U * prev_tmp) >> 1;
    b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(combined_input + 8) >> 4))) + 1U)) >> 1;
    prev_tmp = current_tmp;
}
}
