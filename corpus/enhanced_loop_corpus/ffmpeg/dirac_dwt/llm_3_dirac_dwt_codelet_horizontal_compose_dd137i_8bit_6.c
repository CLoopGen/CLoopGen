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
int *indices = (int*)alloca(w2 * sizeof(int));
for (int i = 0; i < w2; i++) {
    indices[i] = w2 - 1 - i;
}
for (x = 0; x < w2; x++) {
    int idx = indices[x];
    b[2 * x] = ((int)(tmp[idx] + 1U)) >> 1;
    b[2 * x + 1] = ((int)((int)(((unsigned int)(b[idx + w2]) + ((int)(9U * tmp[idx] + 9U * tmp[idx + 1] - tmp[idx + 2] - tmp[idx - 1] + 8) >> 4))) + 1U)) >> 1;
}
}
