#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with pointer arithmetic instead of indexing
    char *ptr = key;
    for (s = 0; s < keylen; s++, ptr++) {
        if (*ptr == '{')
            break;
    }
}
