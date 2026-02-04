#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern size_t f;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(n * sizeof(size_t));
    for (f = 1, l = 2; l <= n; l++) {
        indices[l-2] = l;
    }
    for (l = 2; l <= n; f = f * indices[l-2], l++)
        ;
    free(indices);
}
