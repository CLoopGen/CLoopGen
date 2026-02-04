#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    const ptrdiff_t limit = 4096;
    for (p = key; offset < limit && *(p + offset) != '\x00'; offset++) {
        if (*(p + offset) == '=')
            break;
    }
    p += offset;
}
