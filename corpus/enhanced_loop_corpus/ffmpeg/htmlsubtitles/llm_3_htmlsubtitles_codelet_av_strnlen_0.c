#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++)
        indices[i] = i;

    size_t j = 0;
    for (i = 0; j < len; j++) {
        i = indices[j];
        if (i >= len || !s[i])
            break;
    }

    free(indices);
}
