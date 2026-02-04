#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t *indices = (ptrdiff_t*)malloc(len * sizeof(ptrdiff_t));
    if (!indices) return;
    for (size_t j = 0; j < len; j++)
        indices[j] = (ptrdiff_t)j;
    for (i = 0; i < len && s[indices[i]]; i++)
        ;
    free(indices);
}
