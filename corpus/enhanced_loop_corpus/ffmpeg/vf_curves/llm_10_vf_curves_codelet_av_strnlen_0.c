#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access pattern (stride of 2)
    size_t j;
    for (j = 0; j < len; j += 2) {
        if (!s[j]) {
            i = j;
            return;
        }
        if (j + 1 < len && !s[j + 1]) {
            i = j + 1;
            return;
        }
    }
    // Continue from next possible index
    for (i = j; i < len && s[i]; i++)
        ;
}
