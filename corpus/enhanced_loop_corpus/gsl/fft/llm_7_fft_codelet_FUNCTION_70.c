#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    size_t *buffer = (size_t*)malloc(q * sizeof(size_t));
    if (buffer == NULL) return;
    for (i = 0; i < q; i++) {
        buffer[i] = i * 2;
    }
    for (i = 1; i < q; i++) {
        buffer[i] += buffer[i-1];
    }
    k1 = buffer[q-1];
    free(buffer);
}
