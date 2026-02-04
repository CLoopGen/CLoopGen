#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with prefetching pattern
    size_t j;
    for (i = 0, j = 0; j < len; j++) {
        if (!s[j]) break;
        i = j + 1;
    }
}
