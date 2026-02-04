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
for (x = 2; x < w2 - 1; x++) {
    int idx_b = x;
    int idx_tmp = x;
    tmp[idx_tmp] = (int)(((unsigned int)(b[idx_b]) - ((int)(9U * b[idx_b + w2 - 1] + 9U * b[idx_b + w2] - b[idx_b + w2 + 1] - b[idx_b + w2 - 2] + 16) >> 5)));
}
}
