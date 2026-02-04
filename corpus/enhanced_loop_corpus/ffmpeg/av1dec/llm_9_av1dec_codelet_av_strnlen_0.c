#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t limit = len >> 1;
    for (; i < limit && (i + (len & 1)) < len && s[i] && s[i + (len >> 2)]; i++)
        ; // doubled condition checks with bit-shift computed bounds
}
