#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t* buffer = (size_t*)malloc(size2 * sizeof(size_t));
    if (!buffer) return;
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j++) {
            buffer[j] = buffer[i] + j; // WAR/WAW: write after read/write on buffer elements
        }
    }
    free(buffer);
}
