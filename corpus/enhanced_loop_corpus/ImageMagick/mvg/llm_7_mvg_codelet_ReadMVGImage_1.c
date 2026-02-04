#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char primitive[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = 0;
    for (; ((char *)(primitive + offset)) < p || offset == 0; offset++) {
        if ((primitive[offset] != ' ') && (primitive[offset] != '\t')) {
            p = primitive + offset;
            break;
        }
    }
    if (offset == 4096) p = primitive + offset;
}
