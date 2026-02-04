#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from the end toward the beginning
    for (i = len > 0 ? len - 1 : 0; len > 0 && i < len && s[i]; i--)
        ;
}
