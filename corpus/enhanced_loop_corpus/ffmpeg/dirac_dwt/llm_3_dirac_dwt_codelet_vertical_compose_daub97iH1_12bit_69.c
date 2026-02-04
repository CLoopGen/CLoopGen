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
int *indices = (int*)malloc(width * sizeof(int));
for (int j = 0; j < width; j++) {
    indices[j] = j;
}
for (int j = 0; j < width; j++) {
    int idx = indices[j];
    b1[idx] = ((unsigned int)(b1[idx]) - ((int)(113 * (b0[idx] + (unsigned int)b2[idx]) + 64) >> 7));
}
free(indices);
}
